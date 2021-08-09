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
# 5 3
# 0 0 1 0 0
# 0 0 2 0 1
# 0 1 2 0 0
# 0 0 1 0 0
# 0 0 0 0 2
