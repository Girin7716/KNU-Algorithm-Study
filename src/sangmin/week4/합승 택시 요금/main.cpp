#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX 200
#define INF 0x1fffffff
#define node pair<int, int> // value, v
using namespace std;
vector<node> map[MAX+1];
int dist[3][MAX+1];

void dijkstra(int index,int num){
    priority_queue < node, vector <node> , greater< node > > pq; // pq value, v
    pq.push(make_pair(0,num));
    dist[index][num] = 0;
    int n1, value, v, dist_value;
    while(!pq.empty()){
        n1 = pq.top().second; // u
        value = pq.top().first; // value
        pq.pop();
        if(dist[index][n1] < value) continue;
        for(int i = 0; i<map[n1].size(); i++){
            v = map[n1][i].second;
            dist_value = map[n1][i].first;
            if(dist[index][v] > value + dist_value){
                dist[index][v] = value + dist_value;
                pq.push(make_pair(dist[index][v],v));
            }
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    vector <int> p;
    int n1, n2, value;
  for(int i = 0; i<fares.size(); i++){
        n1 = fares[i][0];
        p = fares[i];
        n2 = p[1];
        value = p[2];
        map[n1].push_back(make_pair(value,n2));
        map[n2].push_back(make_pair(value,n1));

   }
    fill(&dist[0][0], &dist[0][n+1], INF);
    fill(&dist[1][0], &dist[1][n+1], INF);
    fill(&dist[2][0], &dist[2][n+1], INF);
        dijkstra(0,s);
        dijkstra(1,a);
        dijkstra(2,b);

    int answer = dist[0][a] + dist[0][b];
    int result;
    for(int i = 1; i<=n; i++){
        result = dist[0][i] + dist[1][i] + dist[2][i];
        if(result < answer)
            answer = result;
    }
    return answer;
}