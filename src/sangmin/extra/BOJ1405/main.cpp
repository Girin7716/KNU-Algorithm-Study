#include <iostream>
#include <algorithm>
#include <cstring>
#define START 14
using namespace std;

bool map[29][29];

int dx[] = {1,-1,0,0}; // 동,서,남,북
int dy[] = {0,0,1,-1};

int n;
double weight[4];
double result = 0;

void dfs(int x, int y, int level, double p);

int main(){
    cin >> n;
    for(int i = 0; i < 4; i++)
        cin >> weight[i];
    for(int dir = 0; dir < 4; dir++){
        memset(map,false,sizeof(map));
        map[START][START] = true;
        dfs(START+dx[dir], START+dy[dir], 1, weight[dir]/100);
    }
    printf("%.11lf\n",result);
    return 0;
}

void dfs(int x, int y, int level, double p){
    if(map[y][x]) // visit
        return;
    if(level == n) {// 성공
        result+=p;
        return;
    }
    map[y][x] = true;
    for(int dir = 0; dir < 4; dir++){
       int nx = x + dx[dir];
       int ny = y + dy[dir];
       if(nx<=START+n && nx>=START-n && ny<=START+n && ny>=START-n){
           dfs(nx,ny,level+1, p * (weight[dir]/100));
       }
    }
    map[y][x] = false;
}