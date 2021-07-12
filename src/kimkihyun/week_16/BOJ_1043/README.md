# 거짓말

예전에 풀어봤던 기억이 나는데 오랜만에 disjoint set 문제를 풀어봐서 좋았다.

## 풀이방법

지민이가 거짓말을 하기 위해서는 진실을 모르는 사람들의 파티에만 거짓말을 할 수 있고, 그 파티의 개수를 찾는 문제이다.

그러므로, 진실을 아는 사람들을 disjoint set을 통해 집합을 묶고, 각각의 파티를 보면서 진실을 모르는 사람들만 있을 경우, answer를 하나씩 올리면 된다.



아래는 전체코드 + 주석이다.

```python
# 거짓말
import sys
input = sys.stdin.readline

# x의 parent를 찾는 함수
def find_parent(parent, x):
    if parent[x] != x:
        # x의 parent가 최종 parent가 아니면 업데이트
        parent[x] = find_parent(parent,parent[x])	
    return parent[x]

# a와 b의 parent를 합침. 더 작은 parent의 숫자쪽으로 update된다.
# 이 문제에서는 parent가 0인 사람들이 진실을 아는 사람이므로 이렇게 함.
def union_parent(parent,a,b):
    a = find_parent(parent,a)
    b = find_parent(parent,b)

    if a < b:
        parent[b] = a
    else:
        parent[a] = b

# parent가 0(즉, 진실을 아는 사람)이면 False, 아니면 True
def check(parent,party):
    for people in party:
        if find_parent(parent,parent[people]) == 0:
            return False
    return True


N,M = map(int,input().split())

know = list(map(int,input().split()))
parent = [i for i in range(N+1)]
for i in know[1:]:
    parent[i] = 0

parties = []
for i in range(M):
    parties.append(list(map(int, input().split())))
	
    # 차례대로 party의 사람들을 보면서, parent가 다르다면 합쳐주기
    for j in range(1, len(parties[i]) - 1):
        if find_parent(parent, parties[i][j]) != find_parent(parent, parties[i][j + 1]):
            union_parent(parent, parties[i][j], parties[i][j + 1])

answer = 0
for party in parties:
    # 차례대로 party를 보면서, 진실을 아는 사람이 없을 경우 answer += 1
    if check(parent,party[1:]):
        answer += 1

print(answer)
```





