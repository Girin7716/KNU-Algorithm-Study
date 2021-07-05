# 미친 로봇

(dfs+백트래킹)에 뭔가 가지친다는 느낌임.

## 풀이 방법

로봇의 이동 횟수는 14보다 작거나 같으므로, 로봇이 움직일 수 있는 판의 크기는 `30*30`은 넘지 못할 것이다.

그러므로, 로봇을 처음에 `(15,15)` 좌표에서 이리저리 움직인다고 생각하고, 루트에서 제일 끝 노드까지 내려가는 동안 방문한 곳을 check 하면서, 만약 방문한 곳에 재방문한다면 백트래킹해주고, 끝까지 움직였는데 재방문이 없을 경우의 확률을 `answer`에 더해주면 된다.



```python
import sys
input = sys.stdin.readline

N,east,west,south,north = map(int,input().split())
# 동,서,남,북으로 맞춰줌
p = [east*0.01,west*0.01,south*0.01,north*0.01]
dx = [0,0,1,-1]
dy = [1,-1,0,0]
answer = 0

# 로봇이 방문한 곳을 check
visited = [[False for _ in range(30)] for _ in range(30)]

def dfs(x,y,cnt,pb):
    global answer
    if cnt == N:	# 로봇이 재방문하지 않고 다 움직일 경우
        answer += pb	# 현재의 확률을 정답에 더해줌.
        return
    visited[x][y] = True	# x,y 좌표 방문 처리
    for i in range(4):	# 동,서,남,북 순으로 움직이면서
        nx = x + dx[i]
        ny = y + dy[i]
        if nx < 0 or nx>=30 or ny<0 or ny>=30 or visited[nx][ny] is True:	# board의 범위를 벗어났거나, 재방문했을경우 수행안함.
            continue
        dfs(nx,ny,cnt+1,pb*p[i])	# nx,ny 좌표 방문
        visited[nx][ny] = False	# 백트래킹하면서 해당 좌표 방문 처리 돌려놓기

dfs(15,15,0,1) #현재 로봇의 위치 x, 현재 로봇의 위치 y,움직인 횟수,현재 확률(1에서 확률을 곱해가면서 최종 확률을 구하기 위해)

print(answer)
```

