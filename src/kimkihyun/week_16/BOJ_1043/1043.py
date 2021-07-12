# 거짓말
import sys
input = sys.stdin.readline

def find_parent(parent, x):
    if parent[x] != x:
        parent[x] = find_parent(parent,parent[x])

    return parent[x]

def union_parent(parent,a,b):
    a = find_parent(parent,a)
    b = find_parent(parent,b)

    if a < b:
        parent[b] = a
    else:
        parent[a] = b


N,M = map(int,input().split())

know = list(map(int,input().split()))
parent = [i for i in range(N+1)]
for i in know[1:]:
    parent[i] = 0

parties = []
for i in range(M):
    parties.append(list(map(int, input().split())))

    for j in range(1, len(parties[i]) - 1):
        if find_parent(parent, parties[i][j]) != find_parent(parent, parties[i][j + 1]):
            union_parent(parent, parties[i][j], parties[i][j + 1])

def check(parent,party):
    for people in party:
        if find_parent(parent,parent[people]) == 0:
            return False
    return True

answer = 0
for party in parties:
    if check(parent,party[1:]):
        answer += 1

print(answer)