#include <iostream>
using namespace std;
int map[50][5];

int dy[] = {1,0,-1,0}; // 우 상 좌 하
int dx[] = {0,-1,0,1}; // 우 상 좌 하

int main(){
    int r1,r2,c1,c2;
    cin >> r1 >> c1 >> r2 >> c2;

    int x = 0, y = 0;
    int value = 1;
    int dir = 0;
    int max = 0;
    while(x != 5001 && y != 5001){
        // cout <<  x << ", " << y << " = " << value << endl;
        if(r1 <= x && x <= r2 && c1 <= y && y <= c2){
            if(max < value) 
                max = value;
            map[x - r1][y - c1] = value;
        }
        switch(dir){
            case 0:
                if(x == y){
                    y = y+1; // 초기화
                    dir = 1; // 상으로 가야함
                    value++;
                    continue;
                }
                break;
            case 1:
                if(x == -y)
                    dir = 2; // 좌로 가야함
                break;
            case 2: 
                if(x == y)
                    dir = 3; // 하로 가야함
                break;
            case 3:
                    if(x == -y)
                        dir = 0; // 우로 가야함
                break;
        }
        x += dx[dir];
        y += dy[dir];
        value++;
    }

    string maxLength = to_string(max);

    for(int i = 0; i <= r2 - r1; i++){
        for(int j = 0; j <= c2 - c1; j++){
            string results = to_string(map[i][j]);
            if(maxLength.size() > results.size()){
                for (int k = 0; k < maxLength.size() - results.size(); k++) {
                    printf(" ");
                }
            }
            cout << results << " ";
        }
        printf("\n");
    }

    return 0;
}