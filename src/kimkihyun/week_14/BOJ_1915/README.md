# 가장 큰 사각형

처음에는 매 좌표마다 사각형의 최대 크기를 계산해서 완전 탐색으로 하는 방법이었다. 그러나 시간초과가 발생해서 어떻게 해야할지 몰라서 아래 사이트를 참고해서 문제를 풀었다.

https://cagongman.tistory.com/18

## 풀이방법

아래는 전체 코드 및 주석이다.

```python
import sys
input = sys.stdin.readline

n, m = map(int,input().split())
board = [list(input().rstrip()) for _ in range(n)]

dp = [[0 for _ in range(m+1)] for _ in range(n+1)]
side = 0	# 최대 사각형 변의 길이를 저장

# input을 완전탐색하면서 (dp[i][j]는 (i,j)좌표가 사각형 우하단이라고 생각함.)
for i in range(n):
    for j in range(m):
        if board[i][j] == '1':	# board의 값이 1일 경우
            # 해당 좌표에 저장된 값 주위의 값들 중 가장 작은 값에 +1을 저장한다.
            dp[i][j] = min(int(dp[i][j-1]),int(dp[i-1][j]),int(dp[i-1][j-1])) + 1
		# 이때 해당 좌표가 현재의 가장 긴 변보다 길다면 side를 update
        if dp[i][j] > side:
            side = dp[i][j]
# 넓이를 구해야하니까 제곱
print(side**2)
```

