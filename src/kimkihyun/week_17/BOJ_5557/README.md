# 1학년

dp 많이 풀어보기

## 풀이방법

처음에는 dfs 및 백트래킹으로 접근했다가 시간초과가 발생했다.

그래서 dp로 풀어야겠다는 생각은 들었지만 풀지못해서 아래 사이트를 참고해서 로직을 파악하고 구현했다.

https://dev-wd.github.io/algorithm/backjoon5557/



아래는 전체 코드 및 주석이다.

```python
# 1학년
N = int(input())
data = list(map(int,input().split()))
dp = [[0 for i in range(21)] for i in range(N)]	# 가로 0~20, 세로 N 만큼의 dp 리스트 선언

dp[0][data[0]] = 1	# 처음 가로줄에서의 data[0](즉, 8)이 될 수 있으므로 1을 넣어준다.
for i in range(N-1):	# 주어진 data를 끝의 숫자를 제외한 원소들을 하나씩 보면서
    for j in range(21):	# 0~20까지의 범위중 0이 아닌 숫자가 있다면,
        if dp[i][j] != 0:
            if j + data[i+1] >= 0 and j + data[i+1] <=20:	# j:현재의 숫자, data[i+1] : 그 다음 숫자가 더했을때 범위가 0~20사이라면
                dp[i+1][j+data[i+1]] += dp[i][j]	# 다음 가로줄에 해당 범위에 속하는 부분에 횟수를 더해준다.
            if j - data[i + 1] >= 0 and j - data[i + 1] <= 20:	# 빼기도 마찬가지.
                dp[i + 1][j-data[i+1]] += dp[i][j]
print(dp[N-2][data[-1]])	# 그 후, dp[N-2]에는 마지막 숫자를 제외한 각 index가 만들어질 수 있는 횟수가 나온다. 그러므로 dp[N-2][data[-1]]의 자리를 출력하면 된다.
```

![image](https://user-images.githubusercontent.com/52579096/127849492-7b152e81-4377-4917-85b5-4231b317d657.png)

- 첫번째 예시의 이차원 dp 리스트를 표현하면 위와 같이 나온다.