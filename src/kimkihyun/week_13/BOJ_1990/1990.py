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


# def prime_list(a,n):
#     # 에라토스테네스의 체 초기화 : n개 요소에 True 설정(소수로 간주)
#     sieve = [True] * (n+1)  #sieve : 체
#
#     # n의 최대 약수가 sqrt(n) 이하이므로 i=sqrt(n)까지 검사
#     m = int(n ** 0.5)
#     for i in range(2,m+1):
#         if sieve[i] == True:    # i가 소수인 경우
#             for j in range(i+i,n,i):    #i 이후 i의 배수들을 False로 판정
#                 sieve[j] = False
#     # 소수 목록 산출
#     return [i for i in range(a,n+1) if sieve[i] == True and str(i) == str(i)[::-1]]
#
# for i in prime_list(a,b):
#     print(i)
# print(-1)