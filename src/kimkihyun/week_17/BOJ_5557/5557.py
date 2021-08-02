# 1학년
N = int(input())
data = list(map(int,input().split()))
dp = [[0 for i in range(21)] for i in range(N)]

dp[0][data[0]] = 1
for i in range(N-1):
    for j in range(21):
        if dp[i][j] != 0:
            if j + data[i+1] >= 0 and j + data[i+1] <=20:
                dp[i+1][j+data[i+1]] += dp[i][j]
            if j - data[i + 1] >= 0 and j - data[i + 1] <= 20:
                dp[i + 1][j-data[i+1]] += dp[i][j]

print(dp[N-2][data[-1]])

# for i in range(N-1):
#     print("{} : ".format(data[i]), end=' ')
#     for j in range(21):
#         print("%2d"%dp[i][j], end =' ')
#     print()