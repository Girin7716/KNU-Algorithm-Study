# 말이 되고픈 원숭이

python3로 제출하면 시간초과가 발생해서, pypy로 제출해서 통과함.

또한, 큐를 사용한 탐색과 우선순위큐를 사용한 탐색 2가지 방법으로 풀어보았는데 큐를 이용한 탐색(bfs)가 압도적으로 통과시간이 빨랐다.

아래에는 bfs에 대한 코드 설명을 하겠다.

## 풀이방법

`평범한 bfs + 원숭이가 말처럼 움직이는 경우` 를 생각해야한다.

처음에는 가장 짧은 거리만을 기록하는 2차원 리스트인 `dist` 를 두어 짧은 길 탐색을 하도록 했지만, 아래와 같은 케이스에서 통과하지 못했다.

```
1
4 4
0 1 1 1
0 0 1 1
1 0 1 1
1 1 1 0
```

- 즉, `(0,0)`에서 만약 원숭이가 말처럼 움직이는걸 먼저 수행해서 `(2,1)` 위치의 dist 값이 1이 되면 이 그래프에서는 원숭이는 우하단 좌표에 도달할 수 없게된다.
  - 여기에서 정답은 처음에 말처럼 움직이는게 아닌 `(2,1)`까지 인접한 칸으로만 움직여서 도달한 뒤 말처럼 움직여야 도달할 수 있다.

그래서 위와 같은 케이스를 생각해서 2차원 리스트 `dist`를 3차원 리스트로 바꾸었다.

- `dist[말처럼 움직인 횟수 k][x좌표][y좌표]`



이를 기반으로 bfs를 수행 한 뒤, `dist[모든 K][H-1][W-1]`를 검사해서 가장 작은 값이 정답이다. 만약에 전부 도달하지 못했다면 -1을 출력하면 된다.



아래는 전체코드이다.

```python
# 말이 되고픈 원숭이
# bfs
from collections import deque
import math

K = int(input())
W,H = map(int,input().split())
board = [list(map(int,input().split())) for _ in range(H)]
dist = [[[math.inf for i in range(W)] for i in range(H)] for _ in range(K+1)]

q = deque()
q.append((0,0,0,K))	# 움직인 횟수, x, y, 말처럼 움직일 수 있는 남은 횟수

# 평상시 움직이는 방향
dx = [1,0,-1,0]
dy = [0,1,0,-1]
# 말처럼 움직이는 방향
kdx = [-1,-2,-2,-1,1,2,2,1]	
kdy = [-2,-1,1,2,-2,-1,1,2]
# 시작 초기화
dist[0][0][0] = 0

while q:
    move,x,y,k = q.popleft()

    # 만약 도착지에 도달하면 그만
    if dist[k][H-1][W-1] != math.inf:
        break

    # 말처럼 움직일 수 있으면 검사
    if k > 0:
        for i in range(8):
            nx = x + kdx[i]
            ny = y + kdy[i]

            if nx < 0 or nx >= H or ny < 0 or ny >= W or board[nx][ny] == 1 or dist[K-k+1][nx][ny] <= (dist[K-k][x][y] + 1):
                continue
            q.append((move+1,nx,ny,k-1))
            dist[K-k+1][nx][ny] = dist[K-k][x][y] + 1
	# 평상시 움직이는거 확인
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]

        if nx < 0 or nx >= H or ny < 0 or ny >= W or board[nx][ny] == 1 or dist[K-k][nx][ny] <= (dist[K-k][x][y] + 1):
            continue

        q.append((move+1,nx,ny,k))
        dist[K-k][nx][ny] = dist[K-k][x][y] + 1

# 최소값 확인
answer = math.inf
for i in range(K+1):
    answer = min(answer, dist[i][H-1][W-1])

if answer == math.inf:
    print(-1)
else:
    print(answer)
```

