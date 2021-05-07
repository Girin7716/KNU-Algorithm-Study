<meta name='type' content ='BruteForce'>
<meta name='BOJ' content='BOJ1027'>
<meta name='difficulty' content='gold4'>
<meta name='url' content='https://www.acmicpc.net/problem/1027'>
<meat name='date' cotent='2021-05-08'>

1. 코드 설명

<hr>

i번째 idx값과 i+n번째 idx값의 기울기를 구하여 i와 i+n 사이의 모든 idx 값에 대해 i와 기울기를 전부 구해준다.

만약 그 기울기가 i 와 i+n의 기울기보다 크거나 같을경우 i+n번째 사이에는 중복된 빌딩이 존재한다는 뜻이다.

반대로 i와 i+n번째 idx의 기울기가 그 사이의 모든 값보다 크다면 그 사이에는 중복된 빌딩이 존재하지 않는다는 뜻이기 때문에 i와 i+n번째 빌딩은 볼수있는 빌딩의 수가 하나 늘어나게 된다.

결국 마지막에서는 모든 빌딩중 가장 큰 값을 가지고 있는 값을 찾으면 된다.

2. 느낀점

<hr>

알고리즘 시간 복잡도가 n^3이나 걸리는 문제이다. 3중 for문을 사용했는데, 다행히 max case가 50개 밖에 되지 않아 매우 짧게 걸렸다.