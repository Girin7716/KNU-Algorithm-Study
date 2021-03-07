#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#define INF 0x1fffffff
#define MAX_NODE 10000
#define node pair<int, int> // v, value
using namespace std;
vector < node > graph[MAX_NODE + 2];
int mac[MAX_NODE];
int star[MAX_NODE];
int dist[2][MAX_NODE+2];
int V,E;
int x,y;
int M,S;

void dijkstra(int k, int max);

int main(){
    cin >> V >> E;
    int u,v,w;
    for(int i = 0; i<E; i++){
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(v,w));
        graph[v].push_back(make_pair(u,w));
    }
    cin >> M >> x;
    for(int i = 0; i<M; i++){
        cin >> mac[i];
        graph[0].push_back(make_pair(mac[i],0));
    }
    dijkstra(0,x);
    graph[0].clear();
    cin >> S >> y;
    for(int i = 0; i<S; i++){
        cin >> star[i];
        graph[0].push_back(make_pair(star[i],0));
    }
    dijkstra(1,y);
    int min = INF;
    for(int i = 0; i<=V; i++){
        if(dist[0][i] != 0 && dist[1][i] != 0)
            if(dist[0][i] + dist[1][i] < min)
                min = dist[0][i] + dist[1][i];
    }
    if(min == INF)
        min = -1;
    cout << min << endl;
}

void dijkstra(int k, int max){
    fill(&dist[k][0], &dist[k][MAX_NODE+1], INF);
    priority_queue < pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > pq; //
    vector<node> init = graph[0];
    pq.push(make_pair(0,0)); // init
    dist[k][0] = 0;
    //value , cur

    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        for(int i = 0; i<graph[u].size(); i++){
            int v = graph[u][i].first;
            int w = graph[u][i].second;
            if(dist[k][u] + w < dist[k][v] && dist[k][u] + w <=max){
                dist[k][v] = dist[k][u] + w;
                pq.push(make_pair(dist[k][v],v));
            }
        }
    }
}

/*

8 11
1 2 2
1 4 1
2 4 2
2 3 1
2 7 8
3 7 3
4 5 2
4 6 1
6 7 6
6 8 4
7 8 2
2 6
1 5
1 4
8

8 11
1 2 2
1 4 1
2 4 2
2 3 1
2 7 8
3 7 4
4 5 2
4 6 1
6 7 6
6 8 4
7 8 2
2 6
1 5
1 4
8

*/