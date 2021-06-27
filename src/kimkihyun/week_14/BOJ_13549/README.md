# 숨바꼭질 3

## 풀이 방법

수빈이가 취할 수 있는 행동은 총 3가지이다.

1. 1초 후 X-1
2. 1초 후 X+1
3. 0초 후 2*X

그리하여, 시간을 우선순위 삼아 우선순위 큐 pq를 선언하여, 수빈이가 움직일 수 있는 경우를 우선순위 큐를 사용한 bfs를 통해 확인하며 이때, 수빈이의 위치가 동생의 위치랑 같을 경우 탐색을 종료하고 해당 시간을 출력하면 된다.

이때, 이미 방문한 위치를 재방문하는 경우를 막고자 visited를 바탕으로 check해주면서 탐색한다.

아래는 전체코드이다.

```PYTHON
# 숨바꼭질 3
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
```

