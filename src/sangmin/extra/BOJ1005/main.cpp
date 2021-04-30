#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 1000
using namespace std;
int T;
int N, K;
int target;
int weight[MAX+1];
int dist[MAX+1];
int indegree[MAX+1];

int main(){
    scanf("%d", &T);

    for(int i = 0; i<T; i++){
        int n1,n2,w;
        vector < vector <int> > graph;
        scanf("%d %d", &N, &K);
        graph.resize(N+1);
        for(int j = 1; j<=N; j++){
            scanf("%d",&w);
            weight[j] = w;
        }

        for(int j = 0; j<K; j++){
            scanf("%d %d",&n1,&n2);
            graph[n1].push_back(n2);
            indegree[n2]++;
        }

        scanf("%d",&target);
       
        queue <int> q;
        for(int j = 1; j<=N; j++)
            if(indegree[j] == 0){
                q.push(j);
                dist[j] = weight[j];
            }

        while(!q.empty()){
            int cur = q.front();
            q.pop();
            if(cur == target) break;

            for(int next : graph[cur]){
                if(--indegree[next] == 0)
                    q.push(next);
                
                if(dist[next] < dist[cur] + weight[next])
                    dist[next] = dist[cur] + weight[next];
            }
        }
        cout << dist[target] << '\n';
        fill(&dist[0], &dist[N+1], 0);
        fill(&weight[0], &weight[N+1], 0);
        fill(&indegree[0], &indegree[N+1], 0);

    }
    return 0;
}
