1. 코드 설명
<hr>
최장 증가 부분 수열 알고리즘을 통해 해결하였다.

i 번째 반도체와 i + n번째 반도체가 조건에 만족하기 위해서는 i 번째 반도체가 향하는 n1이 항상 i + n 번째 반도체가 향하는 n2 보다 작아야 한다.

이는 증가하는 부분 수열을 뜻하기 때문에 이진 탐색을 이용한 최장 증가 부분수열의 길이를 구하였다.

쉽게 예를 들어 설명하자면

1   7   8   2   3   4   5
순으로 num이 들어온다면

증가 수열을 일부분 구해보자면
1 7 8
1 2 3 4 5
이렇게 크게 2가지가 나온다.


문제와는 다른 방식이지만 이를 dp로 구할 수도 있다. (본인은 이진 탐색을 통해 구현했다.)

i 번째 num의 차례이면 i 번째까지 탐색 후, i 번째 num보다 작고, 그 중 가장 큰 dp값을 가져오고 난 후 + 1을 해주면 된다.
여기서 dp 배열은 i 번째 num이 들어 갔을 때, 나올 수 있는 최장 증가 부분 수열의 길이이다.
1 7 8 2 3 4 5 를 dp로 풀자면

dp 배열은 1, (1) + 1, (1+1) + 1, (1) + 1, (1+1) + 1, (1+1+1) + 1, (1+1+1+1) + 1 중 가장 큰 값을 구하면 최장 증가 수열의 길이가 된다. -> 5

dp를 통해 구현하면 이 전까지 구했던 배열을 전부 비교 한 다음 max 값을 구하고 그 max 값에 + 1을 해준다. 이렇게 해버리면 시간 복잡도가 n^2가 나와버린다.

이를 줄이기 위해선 이진 탐색이 필요하다. 이진 탐색의 개념은 이렇다.
만약
1 7 8 까지 구했다면 이 수열은 1 7 8이 되고 max 길이는 3이 된다.
하지만 이 이후에 들어오는게 만약 0이라면 이는 새로운 수열의 시작이 될 수 있다. 하지만 0이 새로운 수열의 시작이 될 수가 있지 이 새로운 수열이 최장 길이가 되는 것이 아니다.
그렇기 때문에 0이 만약 최장 수열의 일부분이라면 해당하는 인덱스 부분에 집어 넣게 된다. 여기서는 1의 자리에 들어가게 될 것이다.
1 7 8 수열이 이미 있는 상태에서 0이 최장 수열의 일부분이라면 무조건 1이 있는 index(처음) 부터 시작할 것이기 때문이다.

1 7 8 이후 들어오는게 2이고, 이 2가 최장 수열의 일부분이라면 어디서 부터 시작하는지 생각해본다면
1 7 8은 이미 있고 2가 들어오고 2가 최장 수열이면 당연히 1 다음에 올 것 이고 7다음에는 올 수 없기 때문에 7의 자리에 들어가게 될 것이다.
1 2 8 -> 아직 max길이는 3이다.
이를 한번 더 하게 되면 1 2 3 까지 오게 되고 이 이후 4가 들어오면 4는 당연히 3다음에 오게 될 것이다.

위의 과정을 계속해서 판단하게 되면 1 2 3 4 5가 나오고 이는 최장 수열이 된다.

하지만 여가서 주의해야할 점은 이 모든 과정을 다른 test case에 적용할 경우 마지막에 나오는 결과값이 무조건적으로 최장 수열이 되지는 않는다. 최장 수열의 길이는 무조건적으로 구할 수 있지만 최장 수열은 구할수가 없는게, 단순히 위치값을 계속해서 정해주는 것이기 때문에 최장수열이 계속해서 바뀌게 되기 때문이다.


2. 느낀점
<hr>
처음에는 dp로 해결하려 했으나 정답도 틀리고 시간도 틀려서 다른 방법을 찾아보았다. 이진 탐색을 통해 시간을 획기적으로 줄였고, 이진탐색을 통해 찾을 수 있다는 방법도 새롭게 알게 되었다. 처음에는 이진 탐색이 이해가 되지 않아 직접 손으로 그려보고 공부하느라 애를 먹었다.