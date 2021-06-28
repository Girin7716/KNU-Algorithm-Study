<meta name='type' content ='bfs & 구현'>
<meta name='BOJ' content='BOJ1159'>
<meta name='difficulty' content='gold5'>
<meta name='url' content='https://www.acmicpc.net/problem/1159'>
<meat name='date' cotent='2021-06-28'>

1. 코드 설명

<hr>

bfs와 구현이 섞인 문제이다.

map은 한 cycle을 돌면 바뀌거나 안바뀌거나 둘중 하나이다.

만약 바뀌지 않았다면 연쇄가 일어나지 않은것이기 때문에 그대로 종료해준다.

이를 판단하기 위해선 각 칸마다 bfs를 해줘야한다.

R,G,B,P의 칸에서 bfs를 하여 4칸 이상 갔을경우 이는 터졌다고 간주한다.

한번에 터트릴 필요없이 bfs할때마다 판단하여 터트려준다.

만약 3칸 이하라면 다시 복구시킨다.

이렇게 한 싸이클을 돌고나면 빈칸이 존재할것이다.

다행히 열마다 행을 판단하면 되기 때문에

아래에서 부터 빈 공간을 카운트해주고 만약 R,G,B,P를 만나게 되면 그 빈 공간만큼 아래로 내려준다.

2. 느낀점

<hr>

구현과 bfs가 섞인 문제였다.

딱히 어렵진않았다.