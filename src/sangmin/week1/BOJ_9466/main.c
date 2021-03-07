
#include <stdio.h>
#include <stdlib.h>

int visit[100001];
int ary[100001];
int cycle[100001];
int cycles = 0;

void start_dfs(int start);
int dfs(int index);

int main(int argc, const char * argv[]) {
    int T;
    int num;
    
    scanf("%d",&T);
    for(int m = 0; m<T; m++){
        scanf("%d",&num);
        cycles = 0;

        for(int i = 1; i<=num; i++){
            scanf("%d",&ary[i]);
            visit[i] = 0;
            cycle[i] = -1;
        }
        for(int i = 1; i<=num; i++){
            if(cycle[i] == -1)
                start_dfs(i);
        }

        int result = num;
        for(int i = 1; i<=num; i++){
            result -= cycle[i];
        }
        printf("%d\n",result);
    }
    return 0;
}

void start_dfs(int start){
    if(cycle[ary[start]] != -1) // 다음 index가 만약 cycle이거나 cycle이 아니면 자연스럽게 start는 cycle이 아니다.
        cycle[start] = 0;
    else{ // 모를 경우 dfs 시작
        int result = dfs(start);
    };
}

int dfs(int index){
    int value = ary[index];
    if(visit[index] == 1){ // dfs를 쭉 따라 가다가 visit했으면 return
        if(cycle[index] != -1){ // 끝까지 갔는데 판단이 된 경우
            cycles = 0;
            return -1;
        }
        else{ // 끝까지 갔는데 판단이 안 된 경우
            cycle[index] = 1;
            cycles = 1;
            return value;
        }
    }
    visit[index] = 1;
    
    int result = dfs(value); // cycle의 시작임
    
    if(cycles == 1)
        cycle[index] = 1;
    else
        cycle[index] = 0;
    
    if(result == ary[index])
        cycles = 0;
    
    return result;
}
