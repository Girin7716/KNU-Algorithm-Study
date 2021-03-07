//
//  main.c
//  BOJ_17143
//
//  Created by 이상민 on 2021/02/25.
//

#include <stdio.h>
#include <stdlib.h>

int R,C,M; // R = 세로, C = 가로
int count = 0;
struct shark{
    int catch;
    int r;
    int c;
    int direction;
    int size;
    int velocity;
};
struct shark sharks[10000];
int map[101][101];
struct shark sharks_queue[10000];
int front, rear;

void eatshark();
void dotask();
void catchfishman(int fishman);

int main(int argc, const char * argv[]) {
    scanf("%d %d %d", &R, &C, &M);
    for(int i = 0; i<M; i++){
        int r,c,s,d,z;
        scanf("%d %d %d %d %d",&r,&c,&s,&d,&z);
        sharks[i].r = r;
        sharks[i].c = c;
        sharks[i].velocity = s;
        sharks[i].direction = d;
        sharks[i].size = z;
    }
    for(int i = 1; i<=C; i++){
        catchfishman(i);
        dotask();
        eatshark();/*
        printf("\n");
        for(int i = 0; i<M; i++)
            printf("%d %d %d %d %d\n",i,sharks[i].catch,sharks[i].r,sharks[i].c,sharks[i].direction);*/
    }
    printf("%d\n",count);
    return 0;
}

void catchfishman(int fishman){
    int min_r = R;
    int min_m = -1;
    for(int i = 0; i<M; i++){
        if(sharks[i].catch == 0 && sharks[i].c == fishman){
            if(min_r >= sharks[i].r ){
                min_m = i;
                min_r = sharks[i].r;
            }
        }
    }
    if(min_m != -1){
        sharks[min_m].catch = 1;
        count += sharks[min_m].size;
    }
}

void dotask(){
    for(int i = 0; i<M; i++){
        if(sharks[i].catch == 0){ //잡히지 않았을 경우에만
            int move_r = 0, move_c = 0;
            int dir, num;
            switch(sharks[i].direction){
                case 1: // 상
                    move_r = R - sharks[i].r +sharks[i].velocity + 1;
                    dir = move_r / (R-1);
                    num = move_r % (R-1);
                    if(dir % 2 == 1){ //방향이 바뀜
                        // 오른쪽으로 남은 값 만큼 이동함
                        if(num == 0)
                            move_r = 2;
                        else{
                            sharks[i].direction = 2;
                            move_r = num;
                        }
                    }
                    else if(dir % 2 == 0){
                        if(num == 0){
                            sharks[i].direction = 2;
                            move_r = R-1;
                        }
                        else
                            move_r = R-num+1;
                    }
                    sharks[i].r = move_r;
                    break;
                case 2: // 하
                    move_r = sharks[i].r + sharks[i].velocity;
                    dir = move_r / (R-1);
                    num = move_r % (R-1);
                    if(dir % 2 == 1){ // 방향이 달라짐 -> 좌로 간다. 0 은 예외
                        if(num == 0)
                            move_r = R-1;
                        else{
                            sharks[i].direction = 1;
                            move_r = R - num +1;
                        }
                    }
                    else if(dir % 2 == 0){
                        if(num == 0){
                            sharks[i].direction = 1;
                            move_r = 2;
                        }
                        else{
                            move_r = num;
                        }
                    }
                    sharks[i].r = move_r;
                    break;
                case 3: // 우로 이동
                    move_c = sharks[i].c + sharks[i].velocity;
                    dir = move_c / (C-1);
                    num = move_c % (C-1);
                    if(dir % 2 == 1){ // 방향이 달라짐 -> 좌로 간다. 0 은 예외
                        if(num == 0)
                            move_c = C-1;
                        else{
                            sharks[i].direction = 4;
                            move_c = C - num +1;
                        }
                    }
                    else if(dir % 2 == 0){
                        if(num == 0){
                            sharks[i].direction = 4;
                            move_c = 2;
                        }
                        else{
                            move_c = num;
                        }
                    }
                    sharks[i].c = move_c;
                    break;
                case 4: // 좌로 이동
                    move_c = C - sharks[i].c +sharks[i].velocity + 1;
                    dir = move_c / (C-1);
                    num = move_c % (C-1);
                    if(dir % 2 == 1){ //방향이 바뀜
                        // 오른쪽으로 남은 값 만큼 이동함
                        if(num == 0)
                            move_c = 2;
                        else{
                            sharks[i].direction = 3;
                            move_c = num;
                        }
                    }
                    else if(dir % 2 == 0){
                        if(num == 0){
                            sharks[i].direction = 3;
                            move_c = C-1;
                        }
                        else
                            move_c = C-num+1;
                    }
                    sharks[i].c = move_c;
                    break;
                    
            } // 움직임
            if(map[sharks[i].r][sharks[i].c] < sharks[i].size){
                if(map[sharks[i].r][sharks[i].c] != 0)
                    for(int k = 0; k<i; k++){
                        if(sharks[k].r == sharks[i].r && sharks[k].c == sharks[i].c)
                            sharks[k].catch = -1;
                    }
                map[sharks[i].r][sharks[i].c] = sharks[i].size; //가장 큰 사이즈를 넣어줌
            }
            else
                sharks[i].catch = -1; // 갔더니 size가 더 작음
        }
    }
}

void eatshark(){
    for(int i = 1; i<= R; i++)
        for(int j = 1; j<=C; j++){
            if(map[i][j] >= 1)
                map[i][j] = 0;
        }
}
