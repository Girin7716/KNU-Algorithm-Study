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

'''
......
......
......
......
......
......
......
......
.Y....
.YG...
RRYG..
RRYGG.
'''