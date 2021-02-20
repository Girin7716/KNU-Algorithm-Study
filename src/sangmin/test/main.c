//
//  main.c
//  backjoon_12100
//
//  Created by 이상민 on 2021/02/18.
//

#include <stdio.h>
#include <stdlib.h>

int MAX = 20;
int max = 0;
int front = 0;
int rear = 0;
int queue[20];

void dfs(int n,int ary[][20],int level);
void push(int num);
void init_queue(int n);
int pop();
int back_pop();

int main(){
    int n;
    int ary[20][20];
    
    scanf("%d",&n);
    
    for(int i = 0; i<n; i++)
        for(int j = 0; j<n; j++){
            scanf("%d",&ary[i][j]);
            if(max < ary[i][j])
                max = ary[i][j];
        }
    
    dfs(n,ary,1);
    printf("%d",max);
}

void dfs(int n, int ary[][20], int level){
    if(level == 6){
        return;
    }

    int copy_ary[n][n];
    for(int i = 0; i<n; i++)
        for(int j = 0; j<n;j++)
            copy_ary[i][j] = ary[i][j];
    //상
    for(int i = 0; i<n; i++){
        init_queue(n);
        for(int j = 0; j<n; j++){
            push(ary[j][i]);
        }
        for(int j = 0; j<n; j++){
            ary[j][i] = pop();
            if(ary[j][i] > max)
                max = ary[j][i];
        }
    }
    dfs(n,ary,level+1);
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++)
            ary[i][j] = copy_ary[i][j];
    }
    
    //하
    for(int i = 0; i<n; i++){
        init_queue(n);
        for(int j = n-1; j>=0; j--){
            push(ary[j][i]);
        }
        
        for(int j = n-1; j>=0; j--){
            ary[j][i] = pop();
            if(ary[j][i] > max)
                max = ary[j][i];
        }
    }
    
    dfs(n,ary,level+1);
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++)
            ary[i][j] = copy_ary[i][j];
    }

    //좌
    for(int i = 0; i<n; i++){
        init_queue(n);
        for(int j = 0; j<n; j++){
            push(ary[i][j]);
        }
        for(int j = 0; j<n; j++){
            ary[i][j] = pop();
            if(ary[i][j] > max)
                max = ary[i][j];
        }
    }
    
    dfs(n,ary,level+1);
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++)
            ary[i][j] = copy_ary[i][j];
    }
    
    //우
    for(int i = 0; i<n; i++){
        init_queue(n);
        for(int j = n-1; j>=0; j--){
            push(ary[i][j]);
        }
        
        for(int j = n-1; j>=0; j--){
            ary[i][j] = pop();
            if(ary[i][j] > max)
                max = ary[i][j];
        }
    }
    
    dfs(n,ary,level+1);
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++)
            ary[i][j] = copy_ary[i][j];
    }
}

void push(int num){
    if(num != 0)
        queue[rear++] = num;
}

int pop(){
    int num = 0;
    if(front > rear - 1)
        return 0;
    
    if(queue[front] == queue[front+1]){
        num = queue[front]*2;
        front = front + 2;
    }
    else
        num = queue[front++];
    
    return num;
}

void init_queue(int n){
    for(int i = 0; i<n; i++)
        queue[i] = 0;
    front = rear = 0;
}
