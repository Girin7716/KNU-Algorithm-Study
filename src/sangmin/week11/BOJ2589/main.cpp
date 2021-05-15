#include <iostream>
#include <queue>
using namespace std;

string map[51];

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

int dist = 0;
int X,Y;

void bfs(int y, int x);

int main(){
    cin >> Y >> X;
    for(int i = 0; i<Y; i++)
        cin >> map[i];

    for(int i = 0; i<Y; i++){
        for(int j = 0; j<X; j++){
            if(map[i][j] == 'L'){
                bfs(i,j);
            }
        }
    }
    cout << dist << endl;
    return 0;
}

void bfs(int y, int x){
    queue < pair < int , int > > q;

    int visit[51][51] = {0};

    q.push(make_pair(y,x));

    visit[y][x] = 1;


    while(!q.empty()){
        int qy = q.front().first;
        int qx = q.front().second;

        if(dist < visit[qy][qx]) dist = visit[qy][qx]-1;

        q.pop();

        for(int dir = 0; dir<4; dir++){
            int nextY = qy+dy[dir];
            int nextX = qx+dx[dir];
            if(nextY >= 0 && nextY < Y && nextX >= 0 && nextX < X){
                if(map[nextY][nextX] == 'L' && !visit[nextY][nextX]){
                    q.push(make_pair(nextY,nextX));
                    visit[nextY][nextX] = visit[qy][qx]+1;
                }
            }
        }
    }
}

/*
5 7
WLLWWWL
LLLWLLL
LWLWLWW
LWLWLLL
WLLWLWW


5 7
WWWWWWL
LLLWLLL
LWLWLWW
LWLWLLL
WLLWLWW

5 7
WWWWWWL
WWWWLLL
WWWWLWW
WWWWLLL
WWWWLWW

5 7
WWWWWWW
LLLWWWW
LWLWWWW
LWLWWWW
WLLWWWW
*/