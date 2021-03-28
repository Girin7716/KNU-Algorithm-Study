# ��ȸ�� ����(SNS)

## Ǯ�� ���

tree dp �����̴�.

�ϴ� tree dp���� �ϳ��� ������ �˾ƾ��Ѵ�.

�װ� �ٷ� ���������̴�. `��������`�̶� `�������տ� �ִ� � �� ������ ���� �������� �ʴ� ��`�̴�.<br>
��, ��� �׷����� ���� �� �������� node���� �����ǵ�, ���⼭ ���������� ������ ���� ���� �ִ�. �̷��� �������յ��� ���� �θ�� �ڽİ� ������ �������־���Ѵ�.

�׷��� �츮�� ���⼭ �� ������ Ǯ�� ���ؼ��� `�ش� ��������`�� ������ ���� �� ��ü node�� �������� ���ָ� �ȴ�.

�̶�, �� ���������� ���ϱ� ���ؼ� dp�� ����Ѵ�

- `dp[now][0] = 1` : ���� ��带 ������ ���
- `dp[now][1] = 0` : ���� ��带 �������� ���� ���
- `dp[now][0] += dp[i][1]` : �����带 ������ ��� �̹Ƿ� �ڽ� ��带 �������� ���� ����� ���� ���Ѵ�.
- `dp[now][1] += max(dp[i][0],dp[i][1])` : �����带 �������� ���� ��� �ΰ��� ��찡 �߻��Ѵ�.
  1. �ڽ� ��带 ������ ���
  2. �ڽ� ��带 �������� ���� ���
  - �� ���� ū ���� �����ָ� �ȴ�.

## �ڵ� ����

```python
N = int(input())
tree =[[] for _ in range(N+1)]
visited = [False] * (N+1)
dp = [[0,0] for _ in range(N+1)]
for _ in range(N-1):
    u,v = map(int,input().split())
    tree[u].append(v)
    tree[v].append(u)
```
- tree ����
- dfs�� ���� visited ����Ʈ ����
- ���� ��带 �������� �������� ���� dp
  - `dp[?][0]` : ? ��� ����
  - `dp[?][1]` : ? ��� ���Ծ���
- ������̴ϱ� �Ѵ� ����

```python
def DFS(now):
    visited[now] = True
    dp[now][0] = 1 # ���� ��� ����
    dp[now][1] = 0 # ���� ��� ������
    for nxt in tree[now]:
        if visited[nxt] is True:
            continue
        DFS(nxt)
        dp[now][0] += dp[nxt][1]
        dp[now][1] += max(dp[nxt][0],dp[nxt][1])
```
- DFS�� ���� leaf node���� ������ �� dp ���� ä���ָ鼭 �ٽ� �Ž��� �ö���鼭 �ڽ� ����� dp ���� ���鼭 ���� �߰����ش�.


```python
# ��ȸ�� ����(SNS)
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
    dp[now][0] = 1 # ���� ��� ����
    dp[now][1] = 0 # ���� ��� ������
    for nxt in tree[now]:
        if visited[nxt] is True:
            continue
        DFS(nxt)
        dp[now][0] += dp[nxt][1]
        dp[now][1] += max(dp[nxt][0],dp[nxt][1])

DFS(1)
print(N-max(dp[1][0],dp[1][1]))
```
- ��ü �ڵ�.

## ������

tree dp ������ �ؾ��Ұ� ����. ������ DFS��