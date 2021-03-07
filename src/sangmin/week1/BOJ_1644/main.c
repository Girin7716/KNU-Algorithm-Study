//
//  main.c
//  backjoon_1644
//
//  Created by 이상민 on 2021/02/20.
//

#include <stdio.h>

int check[4000001];

void check_num(int num){
    check[1] = -1;
    for(int i = 2; i<=num; i++){
        if(check[i] == 0){
            int n = 2;
            check[i] = 1;
            while(i * n <=num){
                check[i*n] = -1;
                n++;
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    int num;
    scanf("%d",&num);
    check_num(num);
    int sum = 0, result = 0;
    int front = 2, rear = 2;
    while(rear <= num){
        if(check[rear] == 1){
            sum += rear;
            if(sum == num)
                result++;
        }
        rear++;
        
        if(sum > num)
            while(sum > num){
                if(check[front] == 1){
                    sum -= front;
                    if(sum == num)
                        result++;
                }
                front++;
            }
    }
    printf("%d",result);
    return 0;
}
