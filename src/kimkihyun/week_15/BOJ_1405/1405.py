import sys
input = sys.stdin.readline

N,east,west,south,north = map(int,input().split())
p = [east*0.01,west*0.01,south*0.01,north*0.01]
dx = [0,0,1,-1]
dy = [1,-1,0,0]
answer = 0

visited = [[False for _ in range(30)] for _ in range(30)]

def dfs(x,y,cnt,pb):
    global answer
    if cnt == N:
        answer += pb
        return
    visited[x][y] = True
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if nx < 0 or nx>=30 or ny<0 or ny>=30 or visited[nx][ny] is True:
            continue
        dfs(nx,ny,cnt+1,pb*p[i])
        visited[nx][ny] = False


dfs(15,15,0,1) #x,y,움직인 횟수,현재 확률

print(answer)