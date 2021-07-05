# N번째 큰 수

처음에는 N*N 배열을 input으로 받아 리스트에 저장한 뒤, 큰 숫자들을 모음들을 우선순위큐로 저장해서 N번 만큼 꺼내고, 데이터를 넣어주는 형식으로 문제를 풀었으나, 메모리 초과가 발생했다.

그리하여 N*N 배열을 받으면 안될거 같아서, 입력을 읽어오면서 해결하고자 했다.

## 풀이방법

1. 첫번째 줄의 숫자들을 MinHeap에 넣어준다.

2. 다음 줄을 읽으면서

   - 읽어온 숫자들을 하나씩 보면서 MinHeap의 숫자보다 크다면 MinHeap에 넣어주고, MinHeap을 하나 꺼내준다.

   - 그러면 MinHeap에는 무조건 N개의 숫자만 남게된다.

3. 위 과정이 마치면, MinHeap에는 N개의 숫자만 남을 것이다.

4. 그러면, MinHeap에서 첫번째 원소는 결국 N번째 큰 수가 되므로 출력하면 된다.

전체 코드

```python
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
```





메모리 초과가 발생한 코드

```python
# 메모리 초과
import sys
import heapq
from collections import deque
input = sys.stdin.readline

N = int(input())
data = [deque() for _ in range(N)]
pq = []

for i in range(N):
    rem = list(map(int,input().split()))
    for j in range(N):
        data[j].append(rem[j])
for i in range(N):
    heapq.heappush(pq,(-data[i][-1],i))
    data[i].pop()

cnt = 0
while cnt != N:
    number, index = heapq.heappop(pq)
    extract = data[index].pop()
    heapq.heappush(pq,(-extract,index))
    cnt+=1

print(-number)
```

