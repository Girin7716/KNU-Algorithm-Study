#include <iostream>
#include <queue>
#define MAX 100001
#define INF 0x1fffff
using namespace std;

int N,K;
int dist[MAX];

int bfs();

int main(){
    cin >> N >> K;
    for(int i = 0; i < MAX; i++){
        dist[i] = INF;
    }
    int result = bfs();
    cout << result << endl;
    return 0;
}

int bfs(){
    queue <int> q;
    dist[N] = 0;
    q.push(N);

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        if(cur == K) return dist[K];
        //왼쪽
        if(cur-1 >= 0 && dist[cur-1] > dist[cur] + 1){
            dist[cur-1] = dist[cur] + 1;
            q.push(cur-1);
        }
        //오른쪽
        if(cur +1 < MAX && dist[cur+1] > dist[cur] + 1){
            dist[cur+1] = dist[cur] + 1;
            q.push(cur+1);
        }
        //2배
        if(cur * 2 < MAX && dist[cur*2] > dist[cur]){
            dist[cur*2] = dist[cur];
            q.push(cur*2);
        }
    }
}

/*
5 17


*/