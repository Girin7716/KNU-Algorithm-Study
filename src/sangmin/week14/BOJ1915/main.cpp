#include <iostream>
#include <algorithm>
#include <cmath>
#define MAX 1002
using namespace std;

int map[MAX][MAX];
int N,M;
int result = 0;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    string str;
    for(int i = 1; i<=N; i++){
        cin >> str;
        for(int j = 1; j<=M; j++)
            map[i][j] = str[j-1] - '0';
    }

    for(int i = 1; i<=N; i++){
        for(int j = 1; j<=M; j++){
            if(map[i][j] != 0){
                map[i][j] = min(min(map[i-1][j-1],map[i-1][j]), map[i][j-1]) + 1;
                map[i][j] > result ? result = map[i][j] : result = result;
            }
        }
    }

    cout << result * result << endl;
    
    return 0;
}

/*
4 4
0100
0111
1110
0010


*/