# 감소하는 수

완전 탐색 문제인거 같다.

옛날에 c++로 풀었던데 기억이 없다...



## 풀이방법

`deque`를 선언해서 `deque`안에는 뒤에 숫자를 붙였을때 감소하는 수가 있는지 검사하는 숫자들의 목록들을 저장해준다.

`deque`에서 `popleft`를 한 숫자 `now`의 제일 끝자리 숫자를 기준으로 해당 숫자보다 작은 숫자들을 뒤에 붙여주고 붙여준 숫자 `rem`을 `deque`에 append해주면서, `decentNums`에도 append해준다. 이렇게하면 `decentNums`에는 감소하는 숫자가 오름차순으로 쌓이게 된다.

이런식으로 반복하면서 `decentNums`안 숫자의 개수가 N보다 크다면 반복문을 멈추거나 혹은 dq가 빈 경우(더이상 감소하는 숫자가 없을 경우) 반복문을 멈춘다.

만약 `decentNums`가 N보다 작거나 같다면, `N`번째 감소하는 숫자가 없으므로 `-1`을,
그 외는 `decentNums[N]`을 출력해주면 된다.



아래는 전체코드이다.

```python
# 감소하는 수
from collections import deque

N = int(input())

decentNums = [i for i in range(10)]
dq = deque([str(i) for i in range(1,10)])

while dq:
    now = dq.popleft()
    for i in range(int(now[-1])):
        rem = now
        rem += str(i)
        dq.append(rem)
        decentNums.append(int(rem))
    if len(decentNums) > N:
        break


if len(decentNums) <= N:
    print(-1)
else:
    print(decentNums[N])
```



