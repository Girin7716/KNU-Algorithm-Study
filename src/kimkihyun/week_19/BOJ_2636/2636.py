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