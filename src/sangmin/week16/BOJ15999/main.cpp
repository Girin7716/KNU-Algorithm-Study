#include <iostream>
#define MAX 2000
using namespace std;

int N, M;
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
char map[MAX][MAX];

long long mod(int num){
    if(num == 1) return 2;
    long long temp;
    if(num % 2){
        temp = mod(num-1);
        return (2 * temp) % 1000000007;
    }else{
        temp = mod(num / 2);
        return (temp * temp) % 1000000007;
    }
}

int main(){
    string str;
    cin >> N >> M;
    for(int i = 0; i<N; i++){
        cin >> str;
        for(int j = 0; j< str.length(); j++)
            map[i][j] = str[j];
    }
    int result = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j<M; j++){
            char here = map[i][j];
            int dir;
            for(dir = 0; dir<4; dir++){
                int nx = j + dx[dir];
                int ny = i + dy[dir];
                if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
                if(map[ny][nx] != here)  break;
            }
            if(dir == 4) result++;
        }
    }
    cout << mod(result) << endl;
    return 0;
}

/*
wb
// wb일때만

ww
wb
bb
ww

ww, bb

2 2
wb
bb

wb
bb

wb
bw

*/