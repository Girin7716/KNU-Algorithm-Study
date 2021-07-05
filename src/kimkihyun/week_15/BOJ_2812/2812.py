# 크게 만들기
N, K = map(int, input().split())
li = list(input())
k, stack = K, []
for i in range(N):
    # 버린 개수가 k개 이하면서, stack에 숫자가 있으며, stack의 끝 숫자가 현재 검사하는 숫자보다 작다면
    while k > 0 and stack and stack[-1] < li[i]:
        stack.pop() # stack 마지막 숫자 버리기
        k -= 1
    # 현재 숫자 넣기
    stack.append(li[i])
print(''.join(stack[:N-K]))