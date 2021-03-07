# 달빛 여우
import heapq
import sys

input = sys.stdin.readline

N, M = map(int, input().split())
graph = [[] for _ in range(N + 1)]
fox_dist = [int(1e13) for i in range(N + 1)]
wolf_dist = [[int(1e13), int(1e13)] for i in range(N + 1)]  # index0 : 다음 속력은 절반, index1 : 다음 속력은 2배
for i in range(M):
    a, b, d = map(int, input().split())
    graph[a].append([d, b])
    graph[b].append([d, a])


def fox_dijkstra():
    pq = []
    heapq.heappush(pq, (0, 1))
    fox_dist[1] = 0

    while pq:
        cost, now = heapq.heappop(pq)
        if fox_dist[now] < cost:
            continue
        for following in graph[now]:
            if fox_dist[following[1]] > fox_dist[now] + following[0]:
                fox_dist[following[1]] = fox_dist[now] + following[0]
                heapq.heappush(pq, (following[0], following[1]))


def wolf_dijkstra():
    pq = []
    heapq.heappush(pq, (0, 1, 1))  # dist, node, index
    flag = False

    while pq:
        dist, now, tp = heapq.heappop(pq)
        # 1로 다시돌아서 다른 경로로 가는게 더 짧을 수 있으니 그에대한 로직
        if dist == 0 and now == 1 and tp == 1 and (flag is False):
            wolf_dist[1][1] = 0
            wolf_dist[1][0] = 0
        elif flag is False:
            wolf_dist[1][0] = int(1e13)
            wolf_dist[1][1] = int(1e13)
            flag = True

        for following in graph[now]:
            if wolf_dist[following[1]][(tp + 1) % 2] < dist:
                continue

            if tp == 1:
                rem_dist = following[0] / 2
            else:
                rem_dist = following[0] * 2

            if wolf_dist[following[1]][(tp + 1) % 2] > wolf_dist[now][tp] + rem_dist:
                wolf_dist[following[1]][(tp + 1) % 2] = wolf_dist[now][tp] + rem_dist
                heapq.heappush(pq, (following[0], following[1], (tp + 1) % 2))


fox_dijkstra()
wolf_dijkstra()

print('fox : ', fox_dist)
print('wolf: ', wolf_dist)

result = 0
for i in range(2, N + 1):
    if fox_dist[i] < min(wolf_dist[i]):
        result += 1

print(result)

#1000000000

# 4 4
# 1 2 1
# 2 3 10
# 2 4 1
# 4 1 1

# 5 5
# 1 2 1
# 1 4 5
# 1 5 3
# 4 5 4
# 2 3 400

# 5 5
# 1 2 1
# 2 3 1
# 1 3 1
# 1 4 1
# 4 5 10000
