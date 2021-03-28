#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX 1000000
using namespace std;

vector <int> graph[MAX+1];
int N;
int dp[2][MAX+1];
bool visit[MAX+1];

void dfs(int start);

int main(){
    cin >> N;
    for(int i = 1; i < N; i++){
        int n1, n2;
        cin >> n1 >> n2;
        graph[n1].push_back(n2);
        graph[n2].push_back(n1);
    }
    dfs(1);

    dp[1][1] < dp[0][1] ? (cout << dp[1][1] << endl) : (cout << dp[0][1] << endl);
    return 0;
}

void dfs(int start){
    if(visit[start] == true) return;
    if(graph[start].size() == 0){ // leaf node
        dp[0][start] = 0;
        dp[1][start] = 1;
        return;
    }
    visit[start] = true;
    for(int i = 0; i<graph[start].size(); i++){
        int next = graph[start][i];
        dfs(next);
    }
    int sum = 0;
    int sum_not = 0;
    for(int i = 0; i<graph[start].size(); i++){
        int node = graph[start][i];
        if(dp[0][node] < dp[1][node])
            sum += dp[0][node];
        else
            sum += dp[1][node];
        
        sum_not += dp[1][node];
    }
    dp[1][start] = sum+1;
    dp[0][start] = sum_not;
}
/*
8
1 2
1 3
1 4
2 5
2 6
4 7
4 8

*/