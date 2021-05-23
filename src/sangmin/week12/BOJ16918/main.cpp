#include <iostream>
using namespace std;

int R,C,N;

char map[203][203];
int bombs[203][203];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

void printMap(){
    for(int i = 1; i<=R; i++){
        for(int j = 1; j<=C; j++)
            cout << map[i][j];
        cout << endl;
    }
}

int main(){
    cin >> R >> C >> N;
    string str;
    cout.tie(NULL);
    for(int i = 1; i<=R; i++){
        cin >> str;
        for(int j = 0; j<str.size(); j++){
            map[i][j+1] = str[j];
            if(map[i][j+1] == 'O')
                bombs[i][j+1] = 3;
        }
    }

    int time = 2;
    while(time <= N){
        if(time%2 == 1){ // 터짐
            for(int i = 1; i<=R; i++){
                for(int j = 1; j<=C; j++){
                    if(bombs[i][j] == time){
                        map[i][j] = '.';
                        bombs[i][j] = 0;
                        for(int dir = 0; dir<4; dir++){
                            map[i+dy[dir]][j+dx[dir]] = '.';
                        }
                    }
                }
            }
        }
        else{ // 설치
            for(int i = 1; i<=R; i++){
                for(int j = 1; j<=C; j++){
                    if(map[i][j] == '.'){
                        bombs[i][j] = time+3;
                        map[i][j] = 'O';
                    }
                }
            }
        }
        time++;
    }
    printMap();
    return 0;
}


/*
6 7 3
.......
...O...
....O..
.......
OO.....
OO.....

6 7 4
.......
...O...
....O..
.......
OO.....
OO.....

6 7 5
.......
...O...
....O..
.......
OO.....
OO.....

6 7 2
.......
...O...
....O..
.......
OO.....
OO.....
*/