# 감소하는 수
from collections import deque

N = int(input())

decentNums = [i for i in range(10)]
dq = deque([str(i) for i in range(1,10)])

while dq:
    now = dq.popleft()
    for i in range(int(now[-1])):
        rem = now
        rem += str(i)
        dq.append(rem)
        decentNums.append(int(rem))
    if len(decentNums) > N:
        break


if len(decentNums) <= N:
    print(-1)
else:
    print(decentNums[N])