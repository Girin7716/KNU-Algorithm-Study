# N번째 큰 수
import heapq
import sys
input = sys.stdin.readline

N = int(input())
pq = []

rem = list(map(int,input().split()))
for r in rem:
    heapq.heappush(pq,r)

for i in range(N-1):
    rem = list(map(int,input().split()))
    for r in rem:
        if pq[0] < r:
            heapq.heappop(pq)
            heapq.heappush(pq,r)
print(pq[0])

# 메모리 초과
# import sys
# import heapq
# from collections import deque
# input = sys.stdin.readline
#
# N = int(input())
# data = [deque() for _ in range(N)]
# pq = []
#
# for i in range(N):
#     rem = list(map(int,input().split()))
#     for j in range(N):
#         data[j].append(rem[j])
# for i in range(N):
#     heapq.heappush(pq,(-data[i][-1],i))
#     data[i].pop()
#
# cnt = 0
# while cnt != N:
#     number, index = heapq.heappop(pq)
#     extract = data[index].pop()
#     heapq.heappush(pq,(-extract,index))
#     cnt+=1
#
# print(-number)