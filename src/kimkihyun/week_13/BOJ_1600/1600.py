# 말이 되고픈 원숭이
# bfs
from collections import deque
import math

K = int(input())
W,H = map(int,input().split())
board = [list(map(int,input().split())) for _ in range(H)]
dist = [[[math.inf for i in range(W)] for i in range(H)] for _ in range(K+1)]

q = deque()
q.append((0,0,0,K))

dx = [1,0,-1,0]
dy = [0,1,0,-1]
kdx = [-1,-2,-2,-1,1,2,2,1]
kdy = [-2,-1,1,2,-2,-1,1,2]
dist[0][0][0] = 0

while q:
    move,x,y,k = q.popleft()

    if dist[k][H-1][W-1] != math.inf:
        break

    if k > 0:
        for i in range(8):
            nx = x + kdx[i]
            ny = y + kdy[i]

            if nx < 0 or nx >= H or ny < 0 or ny >= W or board[nx][ny] == 1 or dist[K-k+1][nx][ny] <= (dist[K-k][x][y] + 1):
                continue
            q.append((move+1,nx,ny,k-1))
            dist[K-k+1][nx][ny] = dist[K-k][x][y] + 1

    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]

        if nx < 0 or nx >= H or ny < 0 or ny >= W or board[nx][ny] == 1 or dist[K-k][nx][ny] <= (dist[K-k][x][y] + 1):
            continue

        q.append((move+1,nx,ny,k))
        dist[K-k][nx][ny] = dist[K-k][x][y] + 1

answer = math.inf
for i in range(K+1):
    answer = min(answer, dist[i][H-1][W-1])

if answer == math.inf:
    print(-1)
else:
    print(answer)

# 1
# 4 4
# 0 1 1 1
# 0 0 1 1
# 1 0 1 1
# 1 1 1 0

#
#
# # 말이 되고픈 원숭이
# # 우선순위 큐
# import heapq
# import math
#
# K = int(input())
# W,H = map(int,input().split())
# board = [list(map(int,input().split())) for _ in range(H)]
# dist = [[[math.inf for i in range(W)] for i in range(H)] for _ in range(K+1)]
#
# pq = []
# heapq.heappush(pq,(0,0,0,K))  #move,x,y,k
#
# dx = [1,0,-1,0]
# dy = [0,1,0,-1]
# kdx = [-1,-2,-2,-1,1,2,2,1]
# kdy = [-2,-1,1,2,-2,-1,1,2]
# dist[0][0][0] = 0
#
# while pq:
#     move,x,y,k = heapq.heappop(pq)
#
#     if dist[k][H-1][W-1] != math.inf:
#         break
#
#     if k > 0:
#         for i in range(8):
#             nx = x + kdx[i]
#             ny = y + kdy[i]
#
#             if nx < 0 or nx >= H or ny < 0 or ny >= W or board[nx][ny] == 1 or dist[K-k+1][nx][ny] <= (dist[K-k][x][y] + 1):
#                 continue
#             heapq.heappush(pq,(move+1,nx,ny,k-1))
#             dist[K-k+1][nx][ny] = dist[K-k][x][y] + 1
#
#     for i in range(4):
#         nx = x + dx[i]
#         ny = y + dy[i]
#
#         if nx < 0 or nx >= H or ny < 0 or ny >= W or board[nx][ny] == 1 or dist[K-k][nx][ny] <= (dist[K-k][x][y] + 1):
#             continue
#
#         heapq.heappush(pq,(move+1,nx,ny,k))
#         dist[K-k][nx][ny] = dist[K-k][x][y] + 1
#
# answer = math.inf
# for i in range(K+1):
#     answer = min(answer, dist[i][H-1][W-1])
#
# if answer == math.inf:
#     print(-1)
# else:
#     print(answer)
#
# # 1
# # 4 4
# # 0 1 1 1
# # 0 0 1 1
# # 1 0 1 1
# # 1 1 1 0