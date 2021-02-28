# ���ÿ�

## Ǯ�� ���
   �־��� ������� �����ϸ� �ȴ�.
   1. ���ÿ��� ��ĭ�� ���������� �����̰�
   2. ���尡��� �� ��´�
   3. �� �� �� �����δ�.
      1. �̶� �� ���Դ°��� �����ϱ� ���� temp�� ���� �ξ� ��ĥ��� �� ū �� ��Ƴ����� �ؾ��Ѵ�.

## ������
�� ������ �ð��ʰ��� ��� �߻��ؼ� �ᱹ ���ͳ��� �ٸ� ������� �ڵ带 ���� �����ߴ�.

������ �� �� ���� ����� �ð��ʰ��� �ߴ��� �� �𸣰ڴ�... ���� dictionary�� �̿��ؼ� Ǯ���µ� �̰� �����ΰǰ� �������̴�.

```python
# ���ÿ�
R, C, M = map(int, input().split())
shark = {}
board = [[0 for _ in range(C + 1)] for _ in range(R + 1)]
for i in range(M):
    r, c, s, d, z = map(int, input().split())
    shark[z] = [r, c, s, d]
    board[r][c] = z


# 1. ���ÿ��� ���������� �� ĭ �̵��Ѵ�.
# 2. ���ÿ��� �ִ� ���� �ִ� ��� �߿��� ���� ���� ����� �� ��´�. �� ������ �����ǿ��� ���� �� �������.
# 3. �� �̵��Ѵ�.

def catch_shark(fisherman):
    global R
    for i in range(1, R + 1):
        if board[i][fisherman] != 0:
            shark_size = board[i][fisherman]
            del (shark[board[i][fisherman]])
            board[i][fisherman] = 0
            return shark_size
    return 0


# d�� 1�� ���� ��, 2�� ���� �Ʒ�, 3�� ���� ������, 4(0)�� ���� ������ �ǹ��Ѵ�.
dx = [0, -1, 1, 0]
dy = [-1, 0, 0, 1]


def move_shark():
    q = []
    for key, value in shark.items():
        r=value[0]
        c=value[1]
        s=value[2]
        d=value[3]

        if d == 0 or d == 3:  # ������ ����, �������� ���
            shark[key][2] = shark[key][2] % (2 * C - 2)
        elif d == 1 or d == 2:  # ������ ��, �Ʒ��� ���
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