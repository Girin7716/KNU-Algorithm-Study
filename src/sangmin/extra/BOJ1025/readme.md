<meta name='type' content ='등차수열'>
<meta name='BOJ' content='BOJ1025'>
<meta name='difficulty' content='gold5'>
<meta name='url' content='https://www.acmicpc.net/problem/1025'>
<meat name='date' cotent='2021-05-18'>

1. 코드 설명

<hr>

코드 설명읋 하기 전에 문제의 설명부터 해야할것 같다.

일단 행과 열이 모두 등차 수열이라는 소리는 선택한 행과 열의 숫자가 등차수열이라는게 아닌,

(0,0) (0,1) (0,2) (0,3) 이나

(3,0) (2,0) (1,0) (0,0), (3,3) (1,1) 같은 행과 열 그 자체가 등차수열이라는 뜻이다.

그렇다면 시작하는 i와 j의 값을 이중 for문을 통해 전부 구해준 다음, 그 i와 j에 대해 또 이중 for문으로 등차를 지정해서 모든 경우의 수를 구해준다.

예를 들어

    i = 2, j = 2일때
    a = 2, b = 2일 경우 (2,2) (0,0)이 될수있고
    a = 2, b = 1일 경우 (2,2) (0,1)이 될수있다.
    a = 2, b = 0일경우 (2,2) (0,2)이 될수있다.
    a = -1, b = -1일 경우 (2,2) (3,3) (4,4) ...... 등이 될수있다.

이 모든 경우의 수를 구하는데 총 시간은 (N*M)^2이 걸릴것이다.


2. 느낀점

<hr>

문제 번역이 매끄럽지 않아 문제 이해하는데 더 시간이 오래걸렸다.