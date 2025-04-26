#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define WALLRATE 30
#define MAXGRIDSIZE 16

typedef struct Point{
	int x;
	int y;
}Point;

typedef struct Cell{
	Point point;
	struct Cell* parent;
	int f;
	int g;
	int h;
}Cell;


int** createMatrix(int n, int m) {
	int** matrix = (int**) malloc(n * sizeof(int*));
	int i;
	
	for (i = 0; i < n; ++i) {
		matrix[i] = (int*) calloc(m, sizeof(int));
	}
	
	return matrix;
}

int** createGrid(int n, int m, int wallRate) {
	int** grid = (int**) malloc(n * sizeof(int*));
	int i, j;
	
	for (i = 0; i < n; ++i) {
		grid[i] = (int*) calloc(m, sizeof(int));
		for (j = 0; j < m; ++j) {
			if (rand() % 100 < wallRate)
				grid[i][j] = 1;
		}
	}
	
	return grid;
}

void freeMatrix(int*** matrix, int n, int m) {
	int** temp = *matrix;
	int i;
	
	for (i = 0; i < n; ++i) {
		free(temp[i]);
	}
	
	free(temp);
	*matrix = NULL;
}

void swap(Cell** x, Cell** y){
	Cell* temp = *x;
	*x = *y;
	*y = temp;
}

void heapifyBackwards(Cell** priorityQueue, int size, int idx){
	int parent = (idx-1) / 2;
	
	if(parent >= 0 && (priorityQueue[idx]->f < priorityQueue[parent]->f)){
		swap(&priorityQueue[idx], &priorityQueue[parent]);
		heapifyBackwards(priorityQueue, size, parent);
	}
}

void insert(Cell** priorityQueue, int* size, Cell* cell){
	priorityQueue[*size] = cell;
	++(*size);
	heapifyBackwards(priorityQueue, *size, *size-1);
}

void heapify(Cell** priorityQueue, int size, int idx) {
	int min = idx;
	int left = 2*idx + 1;
	int right = 2*idx + 2;
	
	if(left < size && priorityQueue[left]->f < priorityQueue[min]->f)
		min = left;
	
	if(right < size && priorityQueue[right]->f < priorityQueue[min]->f)
		min = right;
	
	if(min != idx) {
		swap(&priorityQueue[min], &priorityQueue[idx]);
		heapify(priorityQueue, size, min);
	}
}

Cell* pop(Cell** priorityQueue, int *size){
	Cell* popped = priorityQueue[0];
	priorityQueue[0] = priorityQueue[*size - 1];
	*size = *size - 1;
	heapify(priorityQueue, *size, 0);
	return popped;
}

int isValid(Point point, int n, int m) {
	if (point.x < 0 || point.y < 0 || point.x >= n || point.y >= m)
		return 0;
	return 1;
}

Cell** initializePriorityQueue(int capacity) {
	Cell** priorityQueue = (Cell**) malloc(capacity * sizeof(Cell*));
	return priorityQueue;
}

/*
int calculateDistance(Point point, Point dest) {
	return (point.x - dest.x) * (point.x - dest.x) + (point.y - dest.y) * (point.y - dest.y);
}
*/

int calculateDistance(Point point, Point dest) {
	return abs(point.x - dest.x) + abs(point.y - dest.y);
}


void printGrid(int** grid, int n, int m) {
	int i, j;
	
	printf("+%.*s+\n", m << 1, "----------------------------------------");
	for(i = 0; i < n; ++i) {
		printf("|");
		for(j = 0; j < m; ++j) {
			if (grid[i][j] == 1)
				printf("o ", grid[i][j]);
			else if (grid[i][j] == 2)
				printf("\033[1;31m* \033[0m");
			else
				printf("  ");
		}
		printf("|\n");
	}
	printf("+%.*s+\n\n", m << 1, "----------------------------------------");
}

Cell* createCell(Point point, Cell* parent, int g, int h) {
	Cell* cell = (Cell*) malloc(sizeof(Cell));
	cell->point = point;
	cell->parent = parent;
	cell->g = g;
	cell->h = h;
	cell->f = g + h;
	return cell;
}

int isEqual(Point p, Point c) {
	if (p.x != c.x || p.y != c.y)
		return 0;
	return 1;
}

void aStar(int** matrix, int n, int m, Point src, Point dest) {
	int** visited = createMatrix(n, m); // 0 -> unvisited
	Cell** priorityQueue = initializePriorityQueue(n * m);
	
	int size = 0, i, found = 0;
	
	if (!isValid(src, n, m) || !isValid(dest, n, m)) {
		printf("source or destination point is not in boundries!\n");
		return;
	}
	
	Cell* start = createCell(src, NULL, 0, calculateDistance(src, dest));
	insert(priorityQueue, &size, start);
	
	int dx[] = {0, 0, 1, 1, 1, -1, -1, -1};
	int dy[] = {1, -1, 1, 0, -1, 1, 0, -1};
	
	while(size != 0 && found == 0) {
		Cell* cur = pop(priorityQueue, &size);
		
		if (cur->point.x == dest.x && cur->point.y == dest.y) {
			printf("Destination found!\n");
			printf("Cost: %d\n", cur->g);
			found = 1;
			
			while(cur != NULL) {
				matrix[cur->point.x][cur->point.y] = 2;
				cur = cur->parent;
			}
			return;
		} else {
			for (i = 0; i < 8; ++i) {
				Point p = {cur->point.x + dx[i], cur->point.y + dy[i]};
				int tentative_g = cur->g + 1;
				if (isValid(p, n, m) && matrix[p.x][p.y] == 0 && (visited[p.x][p.y] == 0 || tentative_g < visited[p.x][p.y])) {
					Cell* c = createCell(p, cur, tentative_g, calculateDistance(p, dest));
					insert(priorityQueue, &size, c);
					visited[p.x][p.y] = tentative_g;
				}
			}
		}
	}
	printf("Destination not found!\n");
}

void simulate() {
	int n = rand() % MAXGRIDSIZE + 1;
	int m = rand() % MAXGRIDSIZE + 1;
	int x1, x2, y1, y2;
	int** grid = createGrid(n, m, WALLRATE);
	
	do {
		x1 = rand() % n;
		x2 = rand() % n;
		y1 = rand() % m;
		y2 = rand() % m;
	} while(grid[x1][y1] != 0 || grid[x2][y2] != 0);
	
	printf("x1: %2d, y1: %2d | x2: %2d, y2: %2d  ->  ", x1, y1, x2, y2);
	
	Point src = {x1, y1};
	Point dest = {x2, y2};

	aStar(grid, n, m, src, dest);
	printGrid(grid, n, m);
	
	freeMatrix(&grid, n, m);
}

int main(){
	srand(time(NULL));
	
	int i;	
	for (i = 0; i < 5; ++i) {
		simulate();
	}	
	
	return 0;
}

