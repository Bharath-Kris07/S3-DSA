#include <stdio.h>
#include <limits.h>
#define MAX 100
#define INF INT_MAX
void findShortestDist(int grid[MAX][MAX], int m, int n) {
    int dist[MAX][MAX];
    int qx[MAX * MAX], qy[MAX * MAX]; 
    int front = 0, rear = 0;
    int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                dist[i][j] = 0;
                qx[rear] = i;
                qy[rear] = j;
                rear++;
            } else {
                dist[i][j] = INF;
            }
        }
    }
    while (front < rear) {
        int x = qx[front];
        int y = qy[front];
        front++;
        for (int k = 0; k < 4; k++) {
            int nx = x + dir[k][0];
            int ny = y + dir[k][1];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                if (dist[nx][ny] > dist[x][y] + 1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    qx[rear] = nx;
                    qy[rear] = ny;
                    rear++;
                }
            }
        }
    }
    printf("\nShortest distance of each cell from nearest landmine:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF)
                printf(" -1 ");
            else
                printf(" %2d ", dist[i][j]);
        }
        printf("\n");
    }
}
int main() {
    int m, n;
    int grid[MAX][MAX];
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &m, &n);
    printf("Enter the maze (0 for empty, 1 for landmine):\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &grid[i][j]);
        }
    }
    findShortestDist(grid, m, n);
    return 0;
}