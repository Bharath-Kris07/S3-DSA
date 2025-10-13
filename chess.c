#include <stdio.h>
#include <stdbool.h>
#define N 8
typedef struct {
    int x, y;
} Position;
bool isValid(int x,int y){
    return (x>=0 && x<N && y>=0 && y<N);
}
int findShortestKnightPath(Position start,Position end){
    int dir[8][2]={{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}};
    int dist[N][N];
    bool visited[N][N];
    Position q[N*N];
    int front=0,rear=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            dist[i][j]=-1;
            visited[i][j]=false;
        }
    }
    dist[start.x][start.y]=0;
    visited[start.x][start.y]=true;
    q[rear++]=start;
    while(front<rear){
        Position curr=q[front++];
        if(curr.x==end.x && curr.y==end.y){
            return dist[curr.x][curr.y];
        }
        for(int i=0;i<8;i++){
            int nx=curr.x+dir[i][0];
            int ny=curr.y+dir[i][1];
            if(isValid(nx,ny) && !visited[nx][ny]){
                visited[nx][ny]=true;
                dist[nx][ny]=dist[curr.x][curr.y]+1;
                Position next={nx,ny};
                q[rear++]=next;
            }
        }
    }
    return -1; 
}
int main(){
    Position start,end;
    printf("Enter starting position (x y): ");
    scanf("%d %d",&start.x,&start.y);
    printf("Enter ending position (x y): ");
    scanf("%d %d",&end.x,&end.y);
    int result=findShortestKnightPath(start,end);
    if(result!=-1){
        printf("Minimum moves required: %d\n",result);
    }else{
        printf("Invalid positions.\n");
    }
    return 0;
}