//
//  main.c
//  BOJ_1937
//
//  Created by 이상민 on 2021/02/26.
//

#include <stdio.h>
int forest[501][501];
int map[501][501];
int n;
int days = 0;
const int move_x[4] = {0,0,-1,1}; // 상,하,좌,우
const int move_y[4] = {-1,1,0,0}; // 상,하,좌,우

int dfs(int i, int j, int day);

int main(int argc, const char * argv[]) {
    scanf("%d",&n);
    for(int i = 1; i<=n; i++)
        for(int j = 1; j<=n; j++)
            scanf("%d",&forest[i][j]);
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            if(map[i][j] == 0)
                dfs(i,j,1);
        }
    }
    printf("%d\n",days);
    return 0;
}

int dfs(int i, int j, int day){
    int move_i = i;
    int move_j = j;
    int value;
    
    map[i][j] = 1;
    int max_map = map[i][j];
    
    for(int dir = 0; dir < 4; dir++){//상,하,좌,우 dfs해줌
        move_i = i + move_y[dir]; // 세로
        move_j = j + move_x[dir]; // 가로
        if(map[move_i][move_j] != 0 && forest[move_i][move_j] < forest[i][j]){
            if(map[move_i][move_j] + 1 > map[i][j])
                map[i][j] = map[move_i][move_j] + 1;
        }
        else if(forest[move_i][move_j] < forest[i][j] && move_i >= 1 && move_i <= n && move_j >= 1 && move_j <= n){ // 갈 수 있으면
            value = dfs(move_i,move_j,day+1);
            if(value + max_map > map[i][j]){
                map[i][j] = max_map + value;
            }
        }
    }
    if(map[i][j] > days)
        days = map[i][j];
    return map[i][j];
}
