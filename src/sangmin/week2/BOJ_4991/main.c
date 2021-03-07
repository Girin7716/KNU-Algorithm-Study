//
//  main.c
//  BOJ_4991
//
//  Created by 이상민 on 2021/02/27.
//

#include <stdio.h>
int w = -1,h = -1;
char map[21][21];
char visit[21][21];
int check[11];
int dp[11][11];
struct object{
    int x,y;
};
int dir_x[4] = {0,0,-1,1};
int dir_y[4] = {-1,1,0,0};

int queue_x[400];
int queue_y[400];
int queue_level[400];
int front;
int rear;

int dirty_count = 1;
int count = 99999;
struct object dirtys[11];

void bfs(int dirty);
void init_queue(){
    front = 0;
    rear = 0;
}
void init_visit(){
    for(int i = 1; i<=h; i++)
        for(int j = 1; j<=w; j++)
            visit[i][j] = 0;
}

void init_dp(){
    for(int i = 0; i<dirty_count; i++)
        for(int j = 0; j<dirty_count; j++)
            dp[i][j] = 0;
}

void init_check(){
    for(int i = 0; i<dirty_count; i++)
        check[i] = 0;
}

void push(int x, int y, int level){
    queue_level[rear] = level;
    queue_x[rear] = x;
    queue_y[rear++] = y;
}

int pop_level(){
    return queue_level[front];
}
int pop_x(){
    return queue_x[front];
}
int pop_y(){
    return queue_y[front++];
}

void dfs(int dp_i,int level,int sum);

int main(int argc, const char * argv[]) {
    while(1){
        scanf("%d %d",&w,&h);
        if(w == 0 && h == 0)
            break;
        dirty_count = 1;
        for(int i = 1; i<= h; i++)
            for(int j = 1; j <= w; j++){
                scanf("%c",&map[i][j]);
                if(map[i][j] == '*'){
                    dirtys[dirty_count].x = j;
                    dirtys[dirty_count++].y = i;
                }
                else if(map[i][j] == 'o'){
                    dirtys[0].x = j;
                    dirtys[0].y = i;
                }
                else if(map[i][j] == '\n')
                    j--;
            }

        for(int i = 0; i<dirty_count;i ++){
            count = 999999;
            init_visit();
            init_queue();
            push(dirtys[i].x, dirtys[i].y,1);
            bfs(i);
        }
        /*
        for(int i = 0; i<dirty_count;i++){
            for(int j = 0; j<dirty_count; j++)
                printf("%2d ",dp[i][j]);
            printf("\n");
        }
        printf("\n");
        */
        init_check();
        dfs(0,1,0);
        for(int i = 1; i<dirty_count; i++)
            if(dp[0][i] == 0){
                count = -1;
                break;
            }
        printf("%d\n",count);
        init_dp();
    }
    return 0;
}

void bfs(int dirty){
    int level = pop_level();
    int x = pop_x();
    int y = pop_y();
    if(front > rear)
        return;
    int next_x, next_y;
    visit[y][x] = level;
    
    for(int i = dirty+1; i < dirty_count; i++)
        if(dirtys[i].x == x && dirtys[i].y == y)
            dp[dirty][i] = level - 1;
        
    for(int i = 0; i<4; i++){
        next_y = y + dir_y[i];
        next_x = x + dir_x[i];
        if(next_y> 0 && next_y <= h && next_x > 0 && next_x <= w)
            if(map[next_y][next_x] != 'x' && visit[next_y][next_x] == 0){
                visit[next_y][next_x] = level+1;
                push(next_x, next_y, level+1);
            }
    }
    bfs(dirty);
}


void dfs(int dp_i,int level,int sum){
    int origin = sum;
    if(level == dirty_count){
        if(sum < count)
            count = sum;
        return;
    }
    for(int i = 1; i<dirty_count; i++){
        if(check[i] == 0){

            check[i] = 1;
            if(dp_i > i)
                sum += dp[i][dp_i];
            else
                sum += dp[dp_i][i];
            dfs(i,level+1,sum);
            sum = origin;
            check[i] = 0;
        }
    }
}
/*
7 5
.......
.**..*.
...*...
.*...o.
.......
 
7 5
.......
.o****.
...*...
.*...*.
.......
 
5 7
.....
.xox.
..x..
..xx.
..x..
..x.x
..x*x
 
5 7
..x..
.xox.
..x..
..xx.
..x..
..x.x
..x*x
 
15 13
.......x.......
...o...x....*..
.......x.......
.......x.......
.......x.......
...............
xxxxx.....xxxxx
...............
.......x.......
.......x.......
.......x.......
..*....x....*..
.......x.......
 
15 13
......*x.......
...**..x....*..
.......x.......
.......x.......
.......x.......
...............
xxxxx.....xxxxx
...............
.......x.......
.*.....x.......
.......x.......
..*....x....o..
.......x.......
 
9 8
o.x......
...x.xxx.
....*....
...x.x.xx
.*x.x...x
...x.*..x
...x..*..
.....x*..
 
7 7
...x..*
.o.x*.*
..x*x..
.......
....xxx
xxx...*
*......
 
 
10 10
..........
..........
..........
..........
..........
.....xxxxx
.....x....
.....x..**
.....xo...
.....x....
 
10 10
..........
..o*******
..........
..........
..........
.....xxxxx
.....x....
.....x....
.*...x....
.....x....
 
20 20
o...................
....................
....................
....................
....................
....................
....................
....................
....................
.........*..........
....................
....................
....................
....................
....................
....................
....................
....................
....................
*..................*
 */
