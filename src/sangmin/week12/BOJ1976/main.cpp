#include <iostream>
#include <vector>
#define MAX 200
using namespace std;

int parent[MAX+1];
vector <int> graph[MAX+1];

int findParent(int start);

int main(){
    bool connect;
    int N, M;
    vector <int> route;

    cin >> N >> M;
    for(int i = 1; i<=N; i++)
        parent[i] = i;

    for(int i = 1; i<= N; i++){
        for(int j = 1; j<=N; j++){
            cin >> connect;
            if(connect){
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }

    int num;
    for(int i = 0; i< M; i++){
        cin >> num;
        route.push_back(num);
    }

    for(int i = 1; i<=N; i++){
        int n1 = i;
        for(int j = 0; j < graph[i].size(); j++){
            int n2 = graph[i][j];
            int nParent1 = findParent(n1);
            int nParent2 = findParent(n2);
            parent[nParent2] = nParent1;
        }
    }

    int startParent = findParent(route[0]);
    for(int i = 1; i < M; i++){
        int routeParent = findParent(route[i]);
        if(startParent != routeParent){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}

int findParent(int start){
    if(parent[start] == start)
        return start;
    return parent[start] = findParent(parent[start]);
}


/*
3
3
0 1 0
1 0 1
0 1 0
1 2 3


5
5
0 1 0 1 1
1 0 1 1 0
0 1 0 0 0
1 1 0 0 0
1 0 0 0 0

4
4
0 1 0 0
1 0 0 0
0 0 0 1
0 0 1 0

1 2
3 4
1 3



5
2
0 1 1 0 0
1 0 0 0 0
1 0 0 0 0
0 0 0 0 1
0 0 0 1 0
1 5
*/