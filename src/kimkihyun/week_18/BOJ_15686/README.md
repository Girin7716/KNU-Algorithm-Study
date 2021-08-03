# 치킨 배달

## 풀이방법

M개의 치킨집과 모든 집과의 가장 짧은 거리를 구하는 문제이다.

그리하여 치킨집 중 순서와 상관없이 M개를 뽑은 경우의 수, 즉 combination을 이용하여, M개의 치킨집을 뽑아준다.

그 후, 해당 치킨집과 모든 집을 보면서 각각의 집에서 가장 가까운 치킨 거리를 구한 뒤, 모두 더해주며 모든 조합의 경우의 수를 보며 가장 작은 값을 선택하면 된다.

여기서, `getAllDistance`에서 현재까지 구한 도시의 치킨 거리가 더 작을 경우 멈춰주도록 했다.



아래는 전체 코드이다.

```python
# 치킨 배달
from itertools import combinations
import sys
input = sys.stdin.readline

N, M = map(int, input().split())
house = []
chicken = []
for i in range(N):
    line = list(map(int, input().split()))
    for j in range(N):
        if line[j] == 1:
            house.append((i, j))
        elif line[j] == 2:
            chicken.append((i, j))


def getDistance(r1, c1, r2, c2):
    return abs(r1 - r2) + abs(c1 - c2)


def getAllDistance(house,comb):
    global answer
    totalDistance = 0
    for r1,c1 in house:
        rem = int(1e9)
        for r2,c2 in comb:
            rem = min(rem,getDistance(r1,c1,r2,c2))
        totalDistance+=rem
        if answer <= totalDistance:
            return answer

    return totalDistance

answer = int(1e9)
for comb in combinations(chicken, M):
    answer = min(answer,getAllDistance(house,comb))
print(answer)
```

