# 로봇 청소기
import sys
from collections import deque
input = sys.stdin.readline

dx = [1,0,-1,0]
dy = [0,1,0,-1]

def bfs(robot_x,robot_y):
    q = deque()
    q.append((0,0,robot_x,robot_y)) # 쓰레기 치운 횟수, move_cnt, x, y
    fullState = (1 << trash_cnt) - 1

    while q:
        state,move_cnt,x,y = q.popleft()

        if state == fullState:
            return move_cnt
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if nx < 0 or nx >= h or ny < 0 or ny >= w or board[nx][ny] == -1:
                continue
            new_state = state
            if board[nx][ny] > 0:
                new_state = new_state | (1<<board[nx][ny]-1)
            if visited[new_state][nx][ny] == True:
                continue
            visited[new_state][nx][ny] = True
            q.append((new_state,move_cnt+1,nx,ny))

    return -1



while True:
    w,h = map(int,input().split())
    if w==0 and h==0:
        break
    board = []
    trash_cnt = 0
    robot_x,robot_y = -1,-1
    for i in range(h):
        board.append(list(input()))
        for j in range(w):
            if board[i][j] == '*':
                trash_cnt += 1
                board[i][j] = trash_cnt
            elif board[i][j] == 'x':
                board[i][j] = -1
            elif board[i][j] == 'o':
                robot_x = i
                robot_y = j
                board[i][j] = 0
            else:
                board[i][j] = 0

    visited = [[[False for _ in range(w)] for _ in range(h)] for _ in range(1<<(trash_cnt+1))]

    print(bfs(robot_x,robot_y))

# 4 4
# ..o.
# ****
# ****
# .**.