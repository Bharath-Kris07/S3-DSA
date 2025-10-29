#include <stdio.h>
#include <stdbool.h>
#define MAX 100 
typedef struct {
    int x, y;
} Position;
Position q[MAX * MAX];
int front = 0, rear = 0;
bool isValid(int x, int y, int m, int n,char grid[m][n]) {
    if(x<0 || x>=m || y<0 || y>=n)
        return false;
    if(grid[x][y]=='X')
        return false;
    return true;
}
void findShortestMineDistance(int m, int n, char grid[m][n]) {
    int dist[MAX][MAX];
    bool visited[MAX][MAX];
    front = 0;
    rear = 0;
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            visited[i][j] = false;
            if (grid[i][j] == 'M') {
                dist[i][j] = 0;       
                visited[i][j] = true; 
                Position minePos = {i, j};
                q[rear++] = minePos;  
            } else {
                dist[i][j] = -1;     
            }
        }
    }
    while (front < rear) {
        Position curr = q[front++];
        for (int i = 0; i < 4; i++) {
            int nx = curr.x + dir[i][0];
            int ny = curr.y + dir[i][1];
            if (isValid(nx, ny, m, n,grid) && !visited[nx][ny]) {
                visited[nx][ny] = true;                   
                dist[nx][ny] = dist[curr.x][curr.y] + 1; 
                Position next = {nx, ny};
                q[rear++] = next;                         
            }
        }
    }
    printf("\nShortest distance from nearest mine ('M'):\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
             if (grid[i][j] == 'M'){
                 printf("  M ");
             } else {
                 printf("%3d ", dist[i][j]); 
        }
    }
    printf("\n");
}
}
int main() {
    int m, n;
    char grid[MAX][MAX]; 
    printf("Enter the dimensions of the grid (rows columns): ");
    scanf("%d %d", &m, &n);
    if (m <= 0 || n <= 0 || m > MAX || n > MAX) {
        printf("Invalid dimensions. Max size is %d x %d.\n", MAX, MAX);
        return 1;
    }
    printf("Enter the grid ('M' for mine, 'O' for open,'X' for wall):\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf(" %c", &grid[i][j]);
            if (grid[i][j] != 'M' && grid[i][j] != 'O' && grid[i][j] != 'X') {
                printf("Invalid character entered: %c. Please use only 'M' or 'O'.\n", grid[i][j]);
                j--; 
            }
        }
    }
    findShortestMineDistance(m, n, grid);
    return 0;
}