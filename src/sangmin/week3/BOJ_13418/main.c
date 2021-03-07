//
//  main.c
//  BOJ_13418
//
//  Created by 이상민 on 2021/03/02.
//

#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int p[MAX + 1];
typedef struct node{
    int a, b, value;
}node;
node nodes[(MAX) * (MAX-1) / 2];
int n,m;
int front,rear;

void init(){
    p[0] = -1;
    p[1] = 0;
    for(int i = 0; i<=n; i++){
        p[i] = i;
    }
    front = 0;
    rear = m;
}

int find_parent(int num){
    if(num == p[num])
        return num;
    return p[num] = find_parent(p[num]);
}

void set_union(int num1, int num2){
    p[num1] = num2;
}

void kruskal(){
    int parent_a, parent_b, value;
    int max_sum = 0, min_sum = 0;
    for(int i = 0; i<=m; i++){
        parent_a = find_parent(nodes[i].a);
        parent_b = find_parent(nodes[i].b);
        value = nodes[i].value;
        if(parent_a != parent_b){
            set_union(parent_a, parent_b);
            if(value == 0)
                max_sum++;
        }
    }
    
    init();
    
    for(int i = m; i >= 0; i--){
        parent_a = find_parent(nodes[i].a);
        parent_b = find_parent(nodes[i].b);
        value = nodes[i].value;
        if(parent_a != parent_b){
            set_union(parent_a, parent_b);
            if(value == 0)
                min_sum++;
        }
    }
    
    printf("%d",max_sum * max_sum - min_sum * min_sum);
}

int main(int argc, const char * argv[]) {
    scanf("%d %d",&n,&m);
    init();
    for(int i = 0; i<=m; i++){
        node temp;
        scanf("%d %d %d",&temp.a, &temp.b, &temp.value);
        if(temp.value == 0)
            nodes[front++] = temp;
        else if(temp.value == 1)
            nodes[rear--] = temp;
    }
    kruskal();
    return 0;
}

/*
5 7
0 1 1
1 2 1
1 4 1
4 2 1
3 4 1
2 3 1
4 5 1
5 3 0
 
4 4
0 1 1
1 2 1
2 3 1
1 4 0
3 1 0

4 5
0 1 1
1 2 0
1 4 0
4 2 1
3 4 0
2 3 0
 
4 5
0 1 1
2 1 0
4 1 0
2 4 1
4 3 0
3 2 0

8 13
0 1 1
1 2 0
2 3 0
3 4 0
4 5 0
5 6 0
6 7 0
7 8 0
8 1 0
1 3 1
1 4 1
1 5 1
1 6 1
1 7 1
 
5 10
0 1 0
1 2 1
2 3 1
3 4 1
4 5 1
5 1 1
1 3 1
1 4 0
2 4 0
5 2 0
5 3 1
 
*/
