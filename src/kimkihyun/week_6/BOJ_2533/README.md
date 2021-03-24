# 사회망 서비스(SNS)

## 풀이 방법

tree dp 문제이다.

일단 tree dp에서 하나의 개념을 알아야한다.

그건 바로 독립집합이다. `독립집합`이란 `독립집합에 있는 어떤 두 정점도 서로 인접하지 않는 것`이다.<br>
즉, 어떠한 그래프가 있을 때 여러개의 node들이 있을건데, 여기서 독립집합은 여러개 나올 수도 있다. 이러한 독립집합들을 보면 부모와 자식간 무조건 떨어져있어야한다.

그러면 우리는 여기서 이 문제를 풀기 위해서는 `극대 독립집합`의 개수를 구한 뒤 전체 node의 개수에서 빼주면 된다.

이때, 이 독립집합을 구하기 위해서 dp를 사용한다

- `dp[now][0] = 1` : 현재 노드를 포함한 경우
- `dp[now][1] = 0` : 현재 노드를 포함하지 않은 경우
- `dp[now][0] += dp[i][1]` : 현재노드를 포함한 경우 이므로 자식 노드를 포함하지 않은 경우의 값을 더한다.
- `dp[now][1] += max(dp[i][0],dp[i][1])` : 현재노드를 포함하지 않은 경우 두가지 경우가 발생한다.
  1. 자식 노드를 포함한 경우
  2. 자식 노드를 포함하지 않은 경우
  - 이 둘중 큰 값을 더해주면 된다.

## 코드 설명

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
- tree 생성
- dfs를 위한 visited 리스트 생성
- 현재 노드를 포함할지 안할지에 대한 dp
  - `dp[?][0]` : ? 노드 포함
  - `dp[?][1]` : ? 노드 포함안함
- 양방향이니까 둘다 연결

```python
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
```
- DFS를 통해 leaf node까지 내려간 뒤 dp 값을 채워주면서 다시 거슬러 올라오면서 자식 노드의 dp 값을 보면서 값을 추가해준다.


```python
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
```
- 전체 코드.

## 느낀점

tree dp 연습을 해야할거 같다. 덤으로 DFS도