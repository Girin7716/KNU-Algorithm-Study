# 숌 사이 수열
N = int(input())
data = list(map(int,input().split()))
data.sort()
diction = {}
for d in data:
    # diction[d] = 2
    diction[d] = diction.get(d,0) + 2

size = len(data) * 2
result = [-1] * size

def dfs(total,length,index):
    if length == size:
        return True
    findIndex = index
    for d in data:
        while findIndex < size:
            if total[findIndex] == -1:
                break
            findIndex+=1
        if findIndex+d+1 < size and total[findIndex] == -1 and total[findIndex+d+1] == -1 and diction[d] != 0:
            total[findIndex] = d
            total[findIndex+d+1] = d
            diction[d] -= 2
            if dfs(total,length+2,index+1):
                return True
            total[findIndex] = -1
            total[findIndex + d + 1] = -1
            diction[d] += 2

    return False

if dfs(result,0,0):
    for r in result:
        print(r,end=' ')
else:
    print(-1)
#
#
# 3
# 1 2 3
# -> 2 3 1 2 1 3
#
# 4
# 1 2 3 4
# -> 2 3 4 2 1 3 1 4
# 4
# 1 2 3 6
# -> 6 2 3 1 2 1 3 6
#
# 1
# 1
# -> -1
#
# 5
# 1 2 3 6 8
# -> 8 6 2 3 1 2 1 3 6 8
#
# 6
# 1 2 3 6 8 10
#
# 7
# 1 2 3 6 8 10 12
#
# 8
# 1 2 3 6 8 10 12 14

# 2
# 0 1
# -1