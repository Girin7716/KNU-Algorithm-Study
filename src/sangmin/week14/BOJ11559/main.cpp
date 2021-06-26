#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

char map[12][6];
bool visit[12][6];
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
int num = 0;

bool bfs(char color,int y,int x, int count);
void move();
void puyo();

int main(){
    for(int i = 0; i<12; i++)
        for(int j = 0; j<6; j++)
            cin >> map[i][j];

    for(int i = 0; i<12; i++)
        for(int j = 0; j<6; j++)
            visit[i][j] = false;

    puyo();
    cout << num-1 << endl;
    return 0;
}

void puyo(){ // map을 계속 돌면서 puyo 시키고 만약 바뀌지 않는다면 종료
    bool flag = true;
    while(flag){
        flag = false;
        for(int i = 0; i<12; i++)
            for(int j = 0; j<6; j++){
                if(!visit[i][j] && map[i][j] != '.'){
                    if(bfs(map[i][j],i,j,1))
                        flag = true;
                }
            }
        move();
        num++;
        for(int i = 0; i<12; i++)
            for(int j = 0; j<6; j++)
                visit[i][j] = false;
    }
}

void move(){
    for(int i = 0; i<6; i++){
        int empty = 0;
        for(int j = 11; j>=0; j--){
            if(map[j][i] == '.')empty++;
            else if(empty!=0){
                map[j+empty][i] = map[j][i];
                map[j][i] = '.';
            }
        }
    }
}

bool bfs(char color, int y, int x, int count){
    int qy[74];
    int qx[74];
    queue < pair <int, int> > q;

    q.push(make_pair(y,x));
    visit[y][x] = true;
    map[y][x] = '.';
    qy[count] = y;
    qx[count] = x;

    while(!q.empty()){
        int ny = q.front().first;
        int nx = q.front().second;
        q.pop();
        for(int i = 0; i<4; i++){
            int nextY = ny + dy[i];
            int nextX = nx + dx[i];
            if(!visit[nextY][nextX] && map[nextY][nextX] == color){
                if(nextY < 12 && nextY >= 0 && nextX < 6 && nextX >= 0){
                    map[nextY][nextX] = '.';
                    visit[nextY][nextX] = true;
                    q.push(make_pair(nextY,nextX));
                    count++;
                    qy[count] = nextY;
                    qx[count] = nextX;
                }
            }
        }
    }
    //탐색 후 종료
    if(count >= 4)
        return true;

    for(int i = 1; i <= count; i++)
        map[qy[i]][qx[i]] = color;
    return false;
}


/*
......
......
......
......
......
......
......
......
.Y....
.YG...
RRYG..
RRYGG.

......
.G....
.G....
.G....
.Y....
.Y....
.Y....
RRR...
RYR...
RYG...
RRYGG.
RRYGGG

GGGGGG
GGGGGG
GGGGGG
GGGGGG
GGGGGG
GGGGGG
GGGGGG
GGGGGG
GGGGGG
GGGGGG
GGGGGG
GGGGGG

......
......
......
......
......
......
.G....
.G....
YY....
RYG...
RRYG..
RRYGG.

......
......
......
......
......
......
......
......
......
......
.G.Y.R
GGYYRR


Y...YR
B.RGGY
R.GGYY
G.RYGR
YGYGRR
YBRYGY
RRYYGY
YYRBRB
YRBGBB
GBRBGR
GBRBGR
GBRBGR

Y....R
B...YY
R.R.YY
G.RYGR
YGYGRR
YBRYGY
RRYYGY
YYRBRB
YRBGBB
GBRBGR
GBRBGR
GBRBGR
1

Y.....
B.....
R.R..R
G.RYGR
YGYGRR
YBRYGY
RRYYGY
YYRBRB
YRBGBB
GBRBGR
GBRBGR
GBRBGR
2

Y.....
B.....
R.R...
G.RY..
YGYGG.
YBRYGY
RRYYGY
YYRBRB
YRBGBB
GBRBGR
GBRBGR
GBRBGR
3

Y.....
B.....
R.R...
G.R...
YGYY..
YBRY.Y
RRYY.Y
YYRBRB
YRBGBB
GBRBGR
GBRBGR
GBRBGR
4

Y.....
B.....
R.....
G.....
YGR...
YBR..Y
RRR..Y
YYRBRB
YRBGBB
GBRBGR
GBRBGR
GBRBGR
5

......
Y.....
B.....
R.....
G.....
YG...Y
YB...Y
YY.BRB
YRBGBB
GBRBGR
GBRBGR
GBRBGR
6

......
......
......
......
......
Y....Y
BG...Y
RB.BRB
GRBGBB
GBRBGR
GBRBGR
GBRBGR
7

......
......
......
......
......
.....Y
.G...Y
.B.BRB
.RBGBB
YBRBGR
BBRBGR
RBRBGR

......
......
......
......
......
.....Y
.....Y
...BRB
..BGBB
.GRBGR
YBRBGR
RRRBGR

......
......
......
......
......
.....Y
.....Y
...BRB
...GBB
...BGR
.G.BGR
YBBBGR

......
......
......
......
......
.....Y
.....Y
....RB
....BB
....GR
...BGR
YG.GGR

......
......
......
......
......
.....Y
.....Y
.....B
.....B
.....R
....RR
YG.BBR

......
......
......
......
......
......
......
......
.....Y
.....Y
.....B
YG.BBB

......
......
......
......
......
......
......
......
......
......
.....Y
YG...Y

bfs후 map을 보고 당김

        // for(int i = 0; i<12; i++){
        //     for(int j = 0; j<6; j++){
        //             cout << map[i][j];
        //         }
        //         cout << endl;
        //     }
        // cout << endl;

*/