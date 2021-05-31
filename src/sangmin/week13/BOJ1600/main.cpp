#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#define MAX 200
using namespace std;

bool map[MAX+1][MAX+1];
int visit[MAX+1][MAX+1][31];
int K,W,H;

int dx[] = {0,0,-1,1}; // 상하좌우
int dy[] = {-1,1,0,0};
int hx[] = {1,2,2,1,-1,-2,-2,-1}; // 90도 부터 시계방향
int hy[] = {-2,-1,1,2,2,1,-1,-2};

void bfs(int starty, int startx){
    queue < pair < pair < int, int > , int > > q; // y, x, curK
    q.push(make_pair(make_pair(starty,startx) , 0 ) );
    visit[starty][startx][0] = 0;


    while(!q.empty()){
        int y = q.front().first.first;
        int x = q.front().first.second;
        int k = q.front().second;
        q.pop();
        for(int i = 0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx > 0 && nx <= W && ny > 0  && ny <= H && !map[ny][nx]){ // 다음에 갈 y,x가 범위보다 작고
                if(visit[ny][nx][k] > visit[y][x][k] + 1){
                    visit[ny][nx][k] = visit[y][x][k] + 1;
                    q.push(make_pair(make_pair(ny,nx) , k ) );
                }
            }
        }
        if(k < K){
            for(int i = 0; i< 8; i++){
                int nx = x + hx[i];
                int ny = y + hy[i];
                if(nx > 0 && nx <= W && ny > 0  && ny <= H && !map[ny][nx]){ // 다음에 갈 y,x가 범위보다 작고
                    if(visit[ny][nx][k+1] > visit[y][x][k] + 1){
                    visit[ny][nx][k+1] = visit[y][x][k] + 1;
                    q.push(make_pair(make_pair(ny,nx) , k+1 ) );
                }
                }
            }
        }
    }
}

int main(){
    cin.tie(NULL);
    cin >> K;
    cin >> W >> H;

    fill(&visit[0][0][0], &visit[MAX][MAX][31], 40001);
    
    for(int i = 1; i<=H; i++)
        for(int j = 1; j<=W; j++)
            cin >> map[i][j];

    for(int i = 0; i<=K; i++)
        visit[1][1][i] = 0;

    bfs(1,1);

    // cout << endl;
    // for(int k = 0; k<=K; k++){
    //     for(int i = 1; i<=H; i++){
    //         for(int j = 1; j<=W; j++)
    //             cout << visit[i][j][k] << " ";
    //         cout << endl;
    //     }
    //     cout << endl;
    // }

    int result = 40002;

    for(int k = 0; k<=K; k++){
        if(visit[H][W][k] < result) 
            result = visit[H][W][k];
    }

    if(result == 40001)
        cout << -1 << endl;
    else
        cout << result << endl;

    return 0;
}

/*
1
4 4
0 0 0 0
1 0 0 0
0 0 1 0
0 1 0 0

1
5 5
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 1 1
0 0 0 1 0

1
5 5
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0


2
5 5
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
*/