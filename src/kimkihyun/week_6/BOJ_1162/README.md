# 도로포장

## 풀이방법

node와 edge가 주어진 부분과 최소 시간을 구해야한다는 점에서 다익스트라를 떠올렸다.

다만, 여기서 K개이하 포장을 할 수 있으며 포장한 도로의 cost가 0이 된다는 점이 추가되었다.

이를 해결하기 위해서는, 평소의 다익스트라할 때 최소 거리의 distance 리스트를 이차원으로 늘려 distance[k][n]으로 만들 필요가 있다.

즉, `distance[k][n]`의 의미는 k개를 포장했을때 n번 노드까지 가는 최소 거리를 저장한다는 뜻이다.

그렇게 다익스트라를 돌려서 distance의 값들을 구하면 `distance[0~K][N]` 중 가장 작은 값을 출력하면 된다.

## 느낀점

dp와 다익스트라가 섞인 느낌..?