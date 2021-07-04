#include <iostream>
using namespace std;

int N;
double dp[4]; // 동서남북
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
bool visit[29][29];
double result = 0;

void dfs(int level, int y, int x, double p);

int main(){
    cin >> N;
    for(int i = 0; i<4; i++)
        cin >> dp[i];

    dfs(0,14,14,1);
    printf("%.11f",result);
    return 0;
}

void dfs(int level, int y, int x, double p){
    if(visit[y][x] == true) return; // 만약 방문한적이 있다면 종료

    if(level == N) {
        result += p;
        return;
    } // 방문한적이 없고 최종 까지 도달하면 result에 더해줌

    visit[y][x] = true;

    for(int i = 0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        double np = p * (dp[i]/(double)100);
        if(nx < 29 && nx >= 0 && ny < 29 && ny >= 0)
            dfs(level+1,ny,nx,np);
    }
    visit[y][x] = false;
}