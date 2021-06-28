<meta name='type' content ='bfs'>
<meta name='BOJ' content='BOJ13549'>
<meta name='difficulty' content='gold5'>
<meta name='url' content='https://www.acmicpc.net/problem/13649'>
<meat name='date' cotent='2021-06-28'>

1. 코드 설명

bfs를 통해 해당 노드까지 도달하는 최단거리를 구하는 문제이다.

N부터 시작하여 할수있는 행동은 -1, +1, 2배 셋중 하나이다.

N부터 시작하여 최대 범위까지 2배씩 계속하여 0을 넣어줄수도 있겠지만 이는 비효율적이기 때문에 bfs방식으로 계속해서 탐색하도록 한다.

dist의 idx는 위치이고 value는 해당 idx까지 도달할수있는 최단거리이다.

N부터 시작했다면 N-1, N+1은 1이 될것이고 2*N은 0이 될것이다.

```cpp
    dist[N-1] = dist[N]+1;
    dist[N+1] = dist[N]+1;
    dist[2*N] = dist[N];
```

만약 dist[k]+1의 값이 dist[k-1]이나 dist[k+1]보다 작다면

dist[k-1], dist[k+1]에 넣어주고 큐에 넣어준다.

이를 계속하다 보면 언젠가는 dist[K]값이 나올것이고 이는 최단거리이기 때문에 답이나온다.

<hr>

2. 느낀점

<hr>

일렬로 되있는 배열을 트리처럼 생각하는게 어려웠던것 같다. 또한 처음에는 2배씩 계속하면 0이기 때문에 이 또한 생각하기 까다로웠다.