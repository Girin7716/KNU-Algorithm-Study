import sys
input = sys.stdin.readline

n, m = map(int,input().split())
board = [list(input().rstrip()) for _ in range(n)]

dp = [[0 for _ in range(m+1)] for _ in range(n+1)]
side = 0

for i in range(n):
    for j in range(m):
        if board[i][j] == '1':
            dp[i][j] = min(int(dp[i][j-1]),int(dp[i-1][j]),int(dp[i-1][j-1])) + 1

        if dp[i][j] > side:
            side = dp[i][j]

print(side**2)


'''
4 4
0100
0111
1110
0010
-> 4

5 5
01100
11110
01110
01111
00011

5 5
01000
01100
01110
00010
01100

5 5
11111
11111
11111
11111
11111

4 4
0100
0111
1111
0011


4 4
1111
0111
1110
0010

'''