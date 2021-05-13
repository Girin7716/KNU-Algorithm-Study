# 보물섬

python3로 제출했을땐 57%에서 시간초과를 받았다. 그래서, pypy로 제출했더니 통과함. 이 문제풀이에서는 내가 푼 방법과 python3에서 통과한 사람의 코드를 주석을 달아주면서 분석하고자 한다.

---

## 풀이방법(내가 푼 방법)

보물 2개를 이어진 육지에서 가장 먼 곳에 설치하여 보물들간의 거리가 가장 먼 거리의 값을 구하는 문제이다.

그래서 bfs를 통한 거리를 구하면 되겠다고 생각했다.

하지만, 보통의 bfs를 통해 거리를 구하면 처음 queue에 넣어준 좌표에 따라 구해지는 값이 달라진다. 그러므로, 주어진 `board` input의 좌표를 하나하나 검사하면서 육지(`L`)일 경우 해당 좌표에서 시작해서 bfs를 돌리면서 해당 좌표에서의 가장 먼 값을 저장하면서, 모든 육지(`L`)를 검사하면서 최댓값을 update해주면 된다.



전체코드

```python
# 보물섬
# L:육지, W: 바다
from collections import deque
N,M = map(int,input().split())
board = [list(input()) for _ in range(N)]

# 방향
dx = [1,0,-1,0]
dy = [0,1,0,-1]

def bfs(x,y):
    q = deque()
    visited = [[0 for _ in range(M)] for _ in range(N)]

    q.append((x,y))
    visited[x][y] = 1
    maxValue = 0
    while q:
        x,y = q.popleft()
        maxValue = max(maxValue,visited[x][y] - 1)
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if nx < 0 or nx >= N or ny < 0 or ny >= M or board[nx][ny] == 'W' or visited[nx][ny] != 0:
                continue
            visited[nx][ny] = visited[x][y] + 1
            q.append((nx,ny))

    return maxValue

answer = 0	# 보물들간 최대 거리 저장 변수
# board를 하나씩 보면서 해당 좌표가 육지일 경우 bfs
for i in range(N):
    for j in range(M):
        if board[i][j] == 'L':
            answer = max(answer,bfs(i,j))

print(answer)
```



## 풀이방법(다른 사람 코드)

참고 : https://www.acmicpc.net/source/17488428

나랑 로직은 거의 비슷하나 차이점은 아래 코드부분이다.

```python
MAX = 0
for m in range(size_y):
    for n in range(size_x):
        if board[m][n] == 'L':
            # 해당 좌표의 육지가 상,하에 육지가 있다면 정답이 될 수 없으니 continue
            if n + dx[2] < size_x and 0 <= n - dx[2]:
                if board[m][n + dx[2]] == 'L' and board[m][n - dx[2]] == 'L':
                    continue
            # 해당 좌표의 육지가 좌,우에 육지가 있다면 정답이 될 수 없으니 continue
            if m + dy[0] < size_y and 0 <= m - dy[0]:
                if board[m + dy[0]][n] == 'L' and board[m + dy[0]][n] == 'L':
                    continue
            compare_cnt = bfs(m, n)
            if MAX < compare_cnt:
                MAX = compare_cnt
print(MAX)
```

- 모든 `L`에서 bfs를 돌리는 것이 아닌, 완전히 후보군이 아니라고 판단되는 육지와 육지 사이에 있는 육지의 경우에는 bfs를 돌리지 않으면 탐색시간이 빨라진다.



## 느낀점

다른 사람 코들르 분석하면서 완전히 답이 안되는 경우 bfs 돌리지 않게끔하는 것이 새로웠다.