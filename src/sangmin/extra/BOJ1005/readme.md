<meta name='type' content ='위상정렬'>
<meta name='BOJ' content='BOJ1005'>
<meta name='difficulty' content='gold3'>
<meta name='url' content='https://www.acmicpc.net/problem/1005'>
<meat name='date' cotent='2021-04-30'>
1. 코드 설명
<hr>
위상 정렬을 이용하여 해당 노드까지 왔을경우 가장 큰 값을 저장해주는 문제이다.

처음에는 목표 노드로 부터 dijkstra를 역으로 사용하여 가장 큰수를 찾게 하였으나 이렇게 하면 시간초과가 나오게 되었다.

인터넷에서 찾아본결과 위상정렬을 통해 푸는 문제였다.

위상 정렬은 노드들간의 선행순서가 존재할때 이를 지키는 정렬이다.

선수과목이 가장 좋은 예이다.

코드를 설명하자면 받는 화살표가 없는 노드는 무조건적으로 시작하게 되는 노드일것이다. 이를 큐에 넣어주고 이와 연결된 노드들의 indgree(연결된 수)를 줄여준다

줄여주면서 만약 연결된 노드들의 indgree가 0이면 이 또한 큐에 넣어준다.

이 과정을 진행하면서 현재 선택된 노드의 dist 값과 연결된 노드의 weight를 더해준값이 만약 현재 연결된 노드의 dist값보다 크다면 현재 연결된 노드의 dist값을

현재 선택된 노드의 dist값과 연결된 노드의 weight를 더해준 값으로 변경해준다. 이를 큐가 빌때까지 진행하면 결국 dist[target]의 값이 정답이 된다.

2. 느낀점
<hr>
위상정렬은 topoplogical sort라고도 하는데, 이는 알고리즘 시간에 배웠던 정렬이다.

하지만 당시에는 단순히 dfs로만 사용하여 값을 출력하면 그게 topological sort가 된다고 배웠기 때문에 본격적으로 배우는것은 처음이었다.

게다가 처음에는 다익스트라로 해결하는줄알고 시간을 낭비했다. 처음 보는 문제이기 때문에 나중에 다시 볼 필요가 있을것같다.