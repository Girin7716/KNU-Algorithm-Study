#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define MAX 300000
#define INF 0x1ffffff
using namespace std;

vector<int> ary [MAX + 1];
int dp[MAX+1][2];
vector<int> value;

int min(int n1, int n2){
    if(n1 < n2)
        return n1;
    return n2;
};

void DFS(int start);

int solution(vector<int> sales, vector<vector<int> > links){
    int answer = 0;
    value = sales;
    for(int i = 0; i < links.size(); i++){
            int p = links[i][0];
            int c = links[i][1];
            ary[p].push_back(c);
    }
    DFS(1);
    answer = min(dp[1][1], dp[1][0]);
    return answer;
}

void DFS(int start){
    if(ary[start].size() == 0){ // leaf
        dp[start][1] = value[start - 1];
        dp[start][0] = 0;
        return;
    }

    for(int i = 0; i < ary[start].size(); i++)
        DFS(ary[start][i]);
    
    int sum = 0;
    bool join = false;
    int min_join = INF;
    for(int i = 0; i < ary[start].size(); i++){
        int n = ary[start][i];
        sum += min(dp[n][1], dp[n][0]);
        if(dp[n][1] <= dp[n][0]) join = true;
        if(min_join > dp[n][1] - dp[n][0]) { min_join = dp[n][1] - dp[n][0];}
    }
    dp[start][1] = value[start - 1] + sum; // 참여
    dp[start][0] = sum + min_join;
    if(join)
        dp[start][0] = sum; 
}