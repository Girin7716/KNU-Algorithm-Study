# Puyo puyo

bfs + 시뮬레이션 문제이다.

코드를 조금 더 깔끔하게 짤 수 있을거 같긴한데 나중에 해보겠다...



## 풀이방법

전체적인 로직은 아래와 같다.

1. `board` 에서 터지는 puyo가 있는지 bfs를 통해서 확인한다.(코드에서는 while문 부분)
   - 이 부분을 `step` 함수로 정의해서하면 깔끔해질듯.
   - 아래 좌표에서부터 하나씩 확인하면서 4개 이상이라면 해당 좌표를 '.'으로 바꿔준다.
   - 만약 하나라도 터트렸다면 bfs의 반환 값으로 1을, 아닐경우 0으로 반환하여, answer에 더해준다.
2. 터트리고 남은 블럭들을 아래로 내려준다.
   - 세로줄에 있는 '.' 이 아닌 블럭들을 rem에 저장한 뒤, 해당 rem을 큐 방식으로 차례대로 꺼내서 바닥에서부터 넣어준다.



아래는 전체 코드이다.

```python
# Puyo Puyo
from collections import deque

row,col = 12, 6
board = [list(input()) for _ in range(row)]
dx = [1,0,-1,0]
dy = [0,1,0,-1]
answer = 0

def bfs(x,y,state):
    q = deque()
    rem = deque()

    cnt = 0
    q.append((x,y))   # x,y
    rem.append((x,y))
    while q:
        x,y = q.popleft()
        cnt+=1
        visited[x][y] = True
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if nx < 0 or nx >= row or ny < 0 or ny >= col or visited[nx][ny] is True or board[nx][ny] != state:
                continue
            q.append((nx,ny))
            rem.append((nx,ny))

    if cnt>=4:
        while rem:
            x,y = rem.popleft()
            board[x][y] = '.'
        return 1

    return 0

while True:
    visited = [[False for _ in range(col)] for _ in range(row)]
    remAnswer = answer
    for i in range(row-1,-1,-1):
        for j in range(col):
            if board[i][j] != '.' and visited[i][j] is False:
                answer += bfs(i,j,board[i][j])
    if remAnswer == answer:
        break
    else:
        answer=remAnswer+1

    # down puyo
    rem = deque()
    for i in range(col):
        for j in range(row-1,-1,-1):
            if board[j][i] != '.':
                rem.append(board[j][i])

        index = 11
        while rem:
            state = rem.popleft()
            board[index][i] = state
            index-=1
        for j in range(index,-1,-1):
            board[j][i] = '.'

print(answer)
```

