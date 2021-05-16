# BOJ 2228 구간나누기 풀이

### 전형적인 DP문제라고 생각하고 풀이를 시작하였음.
### 이차원배열 dp를 정의하고 dp[N][M]을 N이 M번째구간에 포함되냐 안되냐에 따라 분류를 하였다.
### N번째 수가 M번째 구간에 포함되는 경우에는 M-1번째 구간에 포함되지 않는 숫자를 찾은후 그숫자뒤 ~ 자신까지 숫자를 더해서 그걸 합으로 한다.
### N번째 수가 M번째 구간에 포함되지 않는경우에는 dp[N][M]이 dp[N][M-1]이 되므로(자기자신은 구간들의 합에 포함되지 않으므로) dp[N][M]과 dp[N][M-1]중큰숫자를 넣도록한다.

# BOJ 2589 보물섬 풀이

### 과거 학교 알고리즘 수업간에 비슷한 문제를 푼적이있어서 쉽게 풀수있었음.
### 전구간 BFS를 돌리면 끝 ! (풀면서도 의아했음)