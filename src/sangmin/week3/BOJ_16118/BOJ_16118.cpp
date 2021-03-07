#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;
enum{
    MAX_ROUTES = 100000,
    MAX_NODES = 4002
};

long long dist[MAX_NODES];
long long wolf_dist[MAX_NODES][2];
vector<pair<long long, int> > adj_list[MAX_NODES];
const long long INF = 4000LL * 100000 * 10 + 1;

int n,m;

void dijkstra();
void wolf_dijkstra();

int main(){
    cin >> n >> m;
    int n1,n2;
    long long value;
    for(int i = 0; i<m; i++){
        cin >> n1 >> n2 >> value;
        adj_list[n1].push_back(make_pair(value*2,n2));
        adj_list[n2].push_back(make_pair(value*2,n1));
    } // adj_list vector에 pair를 넣어 list를 관리하겠다.

    dijkstra();
    wolf_dijkstra();

    int cnt = 0;
    for(int i = 2; i<=n; i++){
        if(dist[i] < min(wolf_dist[i][0], wolf_dist[i][1]))
            cnt++;
    }
    cout << cnt << endl;
    return 0;
}

void wolf_dijkstra(){
    fill(&wolf_dist[0][0], &wolf_dist[MAX_NODES-1][1] + 1, INF);
    wolf_dist[1][0] = 0;

    priority_queue <pair< pair<long long, int>, int >, vector< pair< pair<long long, int>, int> >, greater< pair< pair<long long, int>, int> > > priority;
    priority.push(make_pair(make_pair(0,1) , 0));

    while(!priority.empty()){
        int cur = priority.top().first.second;
        long long value = priority.top().first.first;
        bool type = priority.top().second;
        priority.pop();

        if(value > wolf_dist[cur][type]) continue;

        if(type){ // 짝수번째 이동
            for(auto &p : adj_list[cur]){
                long long new_cost = value + p.first * 2;
                int n2 = p.second;
                if(wolf_dist[n2][0] > new_cost){
                    priority.push(make_pair(make_pair(new_cost,n2),0));
                    wolf_dist[n2][0] = new_cost;
                }
            }
        }
        else{ //홀수번째
            for(auto &p : adj_list[cur]){
                long long new_cost = value + p.first / 2;
                int n2 = p.second;
                if(wolf_dist[n2][1] > new_cost){
                    priority.push(make_pair(make_pair(new_cost,n2),1));
                    wolf_dist[n2][1] = new_cost;
                }
            }
        }
    }
}

void dijkstra(){ // fox
    fill(dist, dist + MAX_NODES, INF);
    priority_queue <pair<long long, int> , vector< pair<long long, int> >, greater<pair<long long, int> > > priority;
    priority.push(make_pair(0,1));
    dist[1] = 0;

    while(!priority.empty()){
        int cur = priority.top().second;
        long long value = priority.top().first;
        priority.pop();

        if(dist[cur] != value) continue;

        for (auto &p : adj_list[cur]){
            int n2 = p.second;
            long long new_cost = p.first + value;
            if(dist[n2] > new_cost){
                dist[n2] = new_cost;
                priority.push(make_pair(new_cost, n2));
            }
        }
    }
}

/*
6 7
1 6 1
1 4 1
1 5 1
4 3 1
3 2 1
2 4 1
2 1 1

5 6
1 2 3
1 3 2
2 3 2
2 4 4
3 5 4
4 5 3

5 6
1 2 5
1 3 2
2 3 2
2 4 4
3 5 4
4 5 3


5 6
1 2 3
1 3 2
2 3 2
2 4 10
3 5 10
4 5 1

4 4
1 2 1000
1 3 1
3 4 1
4 2 1

5 5
1 2 1
1 4 5
1 5 3
4 5 4
2 3 400
*/
