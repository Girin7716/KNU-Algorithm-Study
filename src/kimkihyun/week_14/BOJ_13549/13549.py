import heapq

N,K = map(int,input().split())

pq = []
visited = [False] * (100001)
heapq.heappush(pq,(0,N))    #cnt, where

while pq:
    cnt,now = heapq.heappop(pq)
    visited[now] = True
    if now == K:
        print(cnt)
        break
    if now+1 <= 100000 and visited[now+1] is False:
        heapq.heappush(pq,(cnt+1,now+1))
    if now-1 >= 0 and visited[now-1] is False:
        heapq.heappush(pq, (cnt+1, now - 1))
    if 2*now <= 100001 and visited[2*now] is False:
        heapq.heappush(pq,(cnt,2*now))