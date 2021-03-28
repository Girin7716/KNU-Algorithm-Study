# Parcel
import sys
input = sys.stdin.readline

w,n = map(int,input().split())
parcel = list(map(int,input().split()))

dp = [False] * (w+1)


def check():
    for i in range(n):
        for j in range(i + 1, n):
            if parcel[i] + parcel[j] < w and dp[w - parcel[i] - parcel[j]] is True:
                return True

        for j in range(i):
            if parcel[i] + parcel[j] < w:
                dp[parcel[i] + parcel[j]] = True


if check():
    print('YES')
else:
    print('NO')