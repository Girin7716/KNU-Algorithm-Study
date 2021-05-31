#include <iostream>
#include <algorithm>
using namespace std;

int ary[10];
int N;
bool flag = false;

void dfs(int cnt, bool * visit ,int * result, int maxlen);

int main(){
    int result[200];
    fill(&result[0], &result[200], -1);
    bool visit[10];
    cin >> N;
    for(int i = 0; i<N; i++)
        cin >> ary[i];
    
    sort(&ary[0], &ary[N]);

    dfs(0, visit ,result, 0);
    if(!flag)   cout << -1 << endl;
    return 0;
}

void dfs(int cnt, bool * visit, int * result, int maxlen){
    if(cnt == N){
        for(int i = 0; i<=maxlen; i++){
            if(result[i] == -1)
            return;
        }
        flag=true;
        for(int i = 0; i<=maxlen; i++){
            cout << result[i] << " ";
        }
        cout << endl;
        return;
    }

    for(int i = 0; i < N; i++){
        if(!visit[i]){
            int num = ary[i]; // 들어갈 숫자
            int idx = 0; // 빈곳
            for(; idx<200; idx++)
                if(result[idx] == -1) break;


            if(result[idx+num+1] == -1){
                int max = idx+num+1;

                if(max < maxlen) max = maxlen;

                result[idx] = num;
                result[idx+num+1] = num;
                visit[i] = true;

                if(!flag)
                    dfs(cnt+1, visit, result, max);

                visit[i] = false;
                result[idx] = -1;
                result[idx+num+1] = -1;
            }
        }
    }
}

/*

3
1 2 3

3
3 2 1

4
1 2 3 6

5
1 2 3 6 8

*/