# 낚시왕

## 풀이 방법
   주어진 로직대로 구현하면 된다.
   1. 낚시왕이 한칸씩 오른쪽으로 움직이고
   2. 가장가까운 상어를 잡는다
   3. 그 후 상어를 움직인다.
      1. 이때 상어가 잡어먹는것을 구현하기 위해 temp를 따로 두어 겹칠경우 더 큰 상어가 살아남도록 해야한다.

## 느낀점
이 문제는 시간초과가 계속 발생해서 결국 인터넷의 다른 사람들의 코드를 보고 구현했다.

아직도 왜 내 구현 방법이 시간초과가 뜨는지 잘 모르겠다... 나는 dictionary를 이용해서 풀었는데 이게 문제인건가 생각중이다.

```python
# 낚시왕
R, C, M = map(int, input().split())
shark = {}
board = [[0 for _ in range(C + 1)] for _ in range(R + 1)]
for i in range(M):
    r, c, s, d, z = map(int, input().split())
    shark[z] = [r, c, s, d]
    board[r][c] = z


# 1. 낚시왕이 오른쪽으로 한 칸 이동한다.
# 2. 낚시왕이 있는 열에 있는 상어 중에서 땅과 제일 가까운 상어를 잡는다. 상어를 잡으면 격자판에서 잡은 상어가 사라진다.
# 3. 상어가 이동한다.

def catch_shark(fisherman):
    global R
    for i in range(1, R + 1):
        if board[i][fisherman] != 0:
            shark_size = board[i][fisherman]
            del (shark[board[i][fisherman]])
            board[i][fisherman] = 0
            return shark_size
    return 0


# d가 1인 경우는 위, 2인 경우는 아래, 3인 경우는 오른쪽, 4(0)인 경우는 왼쪽을 의미한다.
dx = [0, -1, 1, 0]
dy = [-1, 0, 0, 1]


def move_shark():
    q = []
    for key, value in shark.items():
        r=value[0]
        c=value[1]
        s=value[2]
        d=value[3]

        if d == 0 or d == 3:  # 방향이 왼쪽, 오른쪽인 경우
            shark[key][2] = shark[key][2] % (2 * C - 2)
        elif d == 1 or d == 2:  # 방향이 위, 아래인 경우
            shark[key][2] = shark[key][2] % (2 * R - 2)

        board[r][c] = 0
        for i in range(shark[key][2]):
            shark[key][0] += dx[shark[key][3] % 4]
            shark[key][1] += dy[shark[key][3] % 4]
            if shark[key][0] > R:
                shark[key][3] = 1
                shark[key][0] = R - 1
            elif shark[key][0] < 1:
                shark[key][3] = 2
                shark[key][0] = 2
            elif shark[key][1] > C:
                shark[key][3] = 4
                shark[key][1] = C - 1
            elif shark[key][1] < 1:
                shark[key][3] = 3
                shark[key][1] = 2

        q.append((shark[key][0],shark[key][1],key))

    for r, c, z in q:
        if board[r][c] == 0:
            board[r][c] = z
        elif board[r][c] > z:
            del (shark[z])
            continue
        elif board[r][c] < z:
            # shark[board[r][c]][4] = True
            del (shark[board[r][c]])
            board[r][c] = z
    return

result = 0
for i in range(1, C + 1):
    result += catch_shark(i)
    move_shark()

print(result)
```