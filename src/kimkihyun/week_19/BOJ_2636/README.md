# 치즈

처음에 문제를 잘못 이해해서 치즈 경계 안쪽 공기에 맞닿은 치즈까지 녹여버려서 오답을 도출했다.

치즈 경계만 녹인다는 사실을 알고 치즈를 bfs해서 탐색하는게 아닌 공기를 bfs 돌려 치즈를 만나면 녹이는 방식으로 문제를 해결했다.

## 풀이방법

- 현재 `board`에서 `(0,0)`에서부터 bfs를 시작.
- bfs 수행 중 치즈를 만나면, 해당 치즈 좌표를 방문했다고 표시하고 0으로 만든 후, 치즈의 개수를 하나 줄인다.
- 만약, bfs 수행 중 방문하지 않았으면서 공기를 만났다면, queue에 넣어주고, 방문 처리 해준다.
- 위 bfs를 남은 치즈가 0이 될때까지 수행해주고, 치즈가 다 없어지기 바로 전 치즈 개수를 저장하기 위해 `remCheese`에 저장함.



아래는 전체 코드이다.

```python
# 치즈
from collections import deque
import sys
input = sys.stdin.readline

height, width = map(int,input().split())
board = []
time = 0
leftCheese = 0
for i in range(height):
    board.append(list(map(int,input().split())))
    for j in range(width):
        if board[i][j] == 1:
            leftCheese += 1


dx = [1,0,-1,0]
dy = [0,1,0,-1]

def bfs():
    global leftCheese
    q = deque()
    q.append((0,0))
    visited[0][0] = True

    while q:
        x,y = q.popleft()

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if nx < 0 or nx >= height or ny < 0 or ny >= width or visited[nx][ny] is True:
                continue
            if board[nx][ny] == 1:
                visited[nx][ny] = True
                board[nx][ny] = 0
                leftCheese -= 1
            elif board[nx][ny] == 0:
                q.append((nx,ny))
                visited[nx][ny] = True

while leftCheese != 0:
    time += 1
    remCheese = leftCheese
    visited = [[False for i in range(width)] for j in range(height)]
    bfs()

print(time)
print(remCheese)
```

