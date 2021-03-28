#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX 10000
#define INF __LONG_LONG_MAX__
using namespace std;

vector < pair <long long, long long> > ary[MAX+1];

long long dist[22][MAX+1];
int N, M, K;

void dijkstra(int start);

int main(){
    cin >> N >> M >> K;
    for(int i = 0; i<M; i++){
        int n1,n2,value;
        cin >> n1 >> n2 >> value;
        ary[n1].push_back(make_pair(value,n2));
        ary[n2].push_back(make_pair(value,n1));
    }
    dijkstra(1);
    long long max = INF;
    for(int k = 0; k<=K; k++)
        if(dist[k][N] < max)
            max = dist[k][N];

    cout << max << endl;
    return 0;
}

void dijkstra(int start){
    fill(&dist[0][0], &dist[21][N], INF);
    priority_queue < pair < pair <long long, int>, int > , vector < pair < pair <long long, int>, int > >, greater < pair < pair <long long, int>, int > > > pq;
    pq.push(make_pair(make_pair(0,start),0));  
    while(!pq.empty()){
        int step = pq.top().second;
        int n1 = pq.top().first.second;
        long long value = pq.top().first.first;
        pq.pop();
        if(value > dist[step][n1]) continue;
        for(int i = 0; i<ary[n1].size(); i++){
            int n2 = ary[n1][i].second;
            long long add_value = ary[n1][i].first;
            if(add_value + value < dist[step][n2]){ // step 그대로
                dist[step][n2] = add_value + value;
                pq.push(make_pair(make_pair(dist[step][n2],n2),step));
            }
            if(step + 1 <= K && value < dist[step + 1][n2]){
                dist[step+1][n2] = value;
                pq.push(make_pair(make_pair(dist[step+1][n2],n2),step+1));
            }
        }
    }
}


/*
4 4 1
1 2 10
2 4 10
1 3 1
3 4 100

4 4 2
1 2 10
2 4 10
1 3 1
3 4 100
*/