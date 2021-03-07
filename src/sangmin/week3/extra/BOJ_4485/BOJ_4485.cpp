#include <iostream>
#include <queue>
#include <algorithm>

#define MAX 130
#define INF 999999999
using namespace std;
#define node pair<int, int>
#define value int

int map[MAX][MAX];
int dist[MAX][MAX];
priority_queue < pair <value, node> , vector< pair<value, node> >, greater<pair <value, node> > > pq;
int n = -1;
int d_x[4] = {0,0,-1,1};
int d_y[4] = {-1,1,0,0};

void dijkstra(){
    fill(&dist[0][0] , &dist[MAX-1][MAX-1], INF);
    dist[0][0] = map[0][0];
    pq.push(make_pair(dist[0][0], make_pair(0,0)));
    while(!pq.empty()){
        int i = pq.top().second.first; //i
        int j = pq.top().second.second; //j
        int d = pq.top().first; // i,j칸의 최소 coin
        pq.pop();
        for(int k = 0; k < 4; k++)
            if(i + d_y[k] >=0 && i + d_y[k] < n && j + d_x[k] >=0 && j + d_x[k] < n)//범위 내
                if(dist[i+d_y[k]][j+d_x[k]] > map[i+d_y[k]][j+d_x[k]] + d){
                    dist[i+d_y[k]][j+d_x[k]] = map[i+d_y[k]][j+d_x[k]] + d;
                    pq.push(make_pair(dist[i+d_y[k]][j+d_x[k]], make_pair(i+d_y[k],j+d_x[k])));
                }
    }
}

int main(){
    int count  = 1;
    while(true){
        cin >> n;
        if(n == 0)
            break;
        for(int i = 0; i<n; i++)
            for(int j = 0; j<n; j++)
                cin >> map[i][j];
        dijkstra();
    cout << "Problem " << count++ << ": " << dist[n-1][n-1] << endl;
    }
}

/*
3
5 5 4
3 9 1
3 2 7
5
3 7 2 0 1
2 8 0 9 1
1 2 1 8 1
9 8 9 2 0
3 6 5 1 5
7
9 0 5 1 1 5 3
4 1 2 1 6 5 3
0 7 6 1 6 8 5
1 1 7 8 3 2 3
9 4 0 7 6 4 1
5 8 3 2 4 8 3
7 4 8 4 8 3 4
*/