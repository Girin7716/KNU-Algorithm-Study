# 영어 읽기
N = int(input())
diction = {}
for _ in range(N):
    data = input()
    if len(data) == 1:
        startEnd = data
        mid = []
    else:
        startEnd = data[0]+data[-1]
        mid = list(data[1:len(data)-1])
        mid.sort()
    mid = str(mid)

    if diction.get(startEnd):
        if diction[startEnd].get(mid):
            diction[startEnd][mid] += 1
        else:
            diction[startEnd][mid] = 1
    else:
        diction[startEnd] = {mid : 1}

M = int(input())
for _ in range(M):
    answer = 1
    sentence = input()
    for data in sentence.split():
        if len(data) == 1:
            startEnd = data
            mid = []
        else:
            startEnd = data[0] + data[-1]
            mid = list(data[1:len(data) - 1])
            mid.sort()
        mid = str(mid)
        if diction.get(startEnd):
            if diction[startEnd].get(mid):
                answer *= diction[startEnd][mid]
            else:
                answer = 0
        else:
            answer = 0

    print(answer)


# 10
# It
# is
# interesting
# that
# people
# can
# read
# some
# grabled
# words
# 1
# It is itnersetnig taht pepole can raed smoe grabeld wrods.

# 6
# a
# b
# aa
# ababa
# aabba
# abcaa
# 4
# a
# aa
# ababa
# abbaa

# 3
# ababA
# Aabaa
# abcaA
# 2
# ababA
# abcaa
# 3
# ababa
# aabba
# abcaa
# 2
# ababa
# abcaa

# 4
# adefb
# ababa
# aabba
# abcaa
# 3
# afedb
# ababa
# abbaa
# 3
# ababa
# aabba
# abcaa
# 2
# ababa
# abbaa

# 2
# aaba
# bbab
# 2
# abaa
# bbbb

# 1
# aaa
# 0