# 사회망 서비스(SNS)
import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**9)

N = int(input())
tree =[[] for _ in range(N+1)]
visited = [False] * (N+1)
dp = [[0,0] for _ in range(N+1)]
for _ in range(N-1):
    u,v = map(int,input().split())
    tree[u].append(v)
    tree[v].append(u)

def DFS(now):
    visited[now] = True
    dp[now][0] = 1 # 현재 노드 포함
    dp[now][1] = 0 # 현재 노드 미포함
    for nxt in tree[now]:
        if visited[nxt] is True:
            continue
        DFS(nxt)
        dp[now][0] += dp[nxt][1]
        dp[now][1] += max(dp[nxt][0],dp[nxt][1])

DFS(1)
print(N-max(dp[1][0],dp[1][1]))