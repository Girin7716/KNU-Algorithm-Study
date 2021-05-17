<meta name='type' content ='dp'>
<meta name='BOJ' content='BOJ2228'>
<meta name='difficulty' content='gold5'>
<meta name='url' content='https://www.acmicpc.net/problem/2228'>
<meat name='date' cotent='2021-05-16'>

1. 코드 설명

<hr>

dp를 사용하는 문제이다.

dp[i][j]를 i 번째 수까지 j개의 구간을 선택했을때 나올수있는 최대합이라고 정의한다면.

2가지 경우가 존재한다.

1. i번째 수가 택해지지 않을경우는 dp[i-1][j]와 값이 같아진다.

    dp[i][j] = dp[i-1][j]

2. i번째 수를 택할경우 각 구간은 인접할수없기 때문에 i - 2 < k < i 인 k가 존재한다면

1 ~ i - 2 까지 j - 1개의 구간을 택한값과 k ~ i 까지 구간합을 더한 값 중 최대값을 가져와야한다.

    dp[i][j] = dp[i-2][j-1] + sum[i] - sum[k-1]

이 두가지 경우에서 큰 경우가 dp[i][j]의 값이기 때문에 max 를 사용하여 해결해준다.

2. 느낀점

<hr>

이번주 문제 중에서 가장 어려웠던 문제가 아닐까 싶다.

인터넷 참조를 많이 했다. 아직까지 이해가 안되는 부분도 있고 그래서 다시 한번 더 봐야할것 같다.
