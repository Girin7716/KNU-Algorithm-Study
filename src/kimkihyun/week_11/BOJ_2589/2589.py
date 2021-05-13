# 보물섬
# L:육지, W: 바다
from collections import deque
N,M = map(int,input().split())
board = [list(input()) for _ in range(N)]

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

answer = 0
for i in range(N):
    for j in range(M):
        if board[i][j] == 'L':
            answer = max(answer,bfs(i,j))

print(answer)

# from collections import deque
#
# N,M = map(int,input().split())
# board = [list(input()) for _ in range(N)]
#
# dx = [1,0,-1,0]
# dy = [0,1,0,-1]
#
# answer = -int(1e9)
#
# def bfs(x,y):
#     q = deque()
#     visited = [[0 for _ in range(M)] for _ in range(N)]
#
#     q.append((x,y,0))
#     maxValue = 0
#     while q:
#         x,y,dist = q.popleft()
#         visited[x][y] = dist
#         maxValue = max(maxValue,dist)
#         for i in range(4):
#             nx = x + dx[i]
#             ny = y + dy[i]
#             if nx < 0 or nx >= N or ny < 0 or ny >= M or visited[nx][ny] != 0 or board[nx][ny] == 'W':
#                 continue
#             visited[nx][ny] = dist+1
#             q.append((nx,ny,dist+1))
#
#     return maxValue
#
# for i in range(N):
#     for j in range(M):
#         if board[i][j] == 'L':
#             answer = max(answer,bfs(i,j))
#
# print(answer)