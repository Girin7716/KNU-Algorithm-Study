# 소수인팰린드롬

처음에는 소수라길래 에라토스테네스의 체로 소수를 구하고 팰린드롬 수를 구하고자 했는데 시간초과.

그다음, [a,b+1] 수에서 팰린드롬일 경우 소수를 확인하고 출력하는 형식으로 했으나 50%에서 시간초과.

그래서 못 풀었음...



## 내가 풀다가 실패한 코드

```python
# 소수인팰린드롬
import math

a,b = map(int,input().split())

def check(num):
    if num == num[::-1]:
        return True
    return False

def isPrime(num):
    if num <= 1:
        return False
    if num % 2 == 0:
        return False

    for i in range(3,int(math.sqrt(num)),2):
        if num % i == 0:
            return False
    return True

for i in range(a,b+1):
    if check(str(i)):
        if isPrime(i):
            print(i)
print(-1)
```



## 나중에 다시 풀때 풀어 볼 방법

처음 팰린드롬 수를 구할 때 dfs와 backtracking을 통해 수를 구한 뒤, [a,b+1] 범위 안 구한 팰린드롬 수가 소수인지 확인하는 방법으로 코딩 해보기.