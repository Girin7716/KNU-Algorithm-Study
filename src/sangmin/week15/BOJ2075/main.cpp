#include <iostream>
#include <queue>
#define MAX 1500
using namespace std;

int map[MAX][MAX];

int idx[MAX]; // i값 들어감

int N;

int main(){
    int result = 0;
    priority_queue < pair<int, int> , vector <pair<int, int > >, less < pair<int, int > > > pq; // value, idx
    scanf("%d",&N);
    for(int i = 0; i<N; i++){
        idx[i] = N-1;
        for(int j = 0; j<N; j++)
            scanf("%d",&map[i][j]);
    }

    for(int i = 0; i<N; i++)
        pq.push(make_pair(map[N-1][i], i));
    
    while(N > 0){
        result = pq.top().first;
        int getIdx = pq.top().second;
        pq.pop();
        idx[getIdx]--;
        pq.push(make_pair(map[idx[getIdx]][getIdx], getIdx));
        N--;
    }
    printf("%d",result);
    return 0;
}

/*
2
1 99999
9999999 1000000000


3
1 2 11
4 5 12
7 8 13

5
12 7 9 15 5
13 8 11 19 6
21 10 26 31 16
48 14 28 35 25
52 20 32 41 49
*/