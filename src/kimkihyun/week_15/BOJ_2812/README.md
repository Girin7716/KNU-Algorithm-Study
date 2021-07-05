# 크게 만들기

스텍이랑 그리디 인거 같은데 구현을 못해서 아래 사이트 코드를 보고 해석하기로 했다.

https://jinho-study.tistory.com/797



## 풀이 방법

1. input으로 들어온 숫자를 하나씩 검사하면서,

2. 버린 횟수가 K보다 작거나, stack이 비거나, stack의 마지막 수가 검사하는 숫자보다 작을 경우, stack의 마지막 숫자를 버리고 버린횟수를 하나 늘려주고 이를 반복한다.

3. 그 후, 현재 검사하는 숫자를 stack에 넣어준다.



이렇게 하면, 앞에서부터 큰 숫자를 가져가면서, 만약 버린 횟수가 K를 넘을 경우 뒤에 숫자는 전부 가져오면 그게 가장 큰 숫자가 된다.

```python
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
```



