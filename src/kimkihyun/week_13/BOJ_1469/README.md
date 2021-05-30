# 숌 사이 수열

이 문제 푸는데 하루동안 고민했다.

결론은 문제를 제대로 읽지 않았고, 제대로 동작하는지 확신하지 않아서 일어난 일이다.

## 풀이방법

문제를 보고 주어진 input data를 정렬하고, 이러한 list를 바탕으로 dfs를 통해 list에 나열하면서 조건에 맞지 않으면 백트래킹하여서 값을 찾고자 했다.

근데 여기서 나는 두 가지 실수를 해서 문제푸는데 오래 걸렸다.

1. 문제에서 ` X의 원소는 0보다 크거나 같고 20보다 작거나 같은 정수이다.`라고 말한다. 여기서 나는 `0보다 크거나 같고`를 제대로 보지 못해서 X의 범위를 `1~20`라 생각하고 문제를 풀었다. 그래서 result 리스트를 처음에 0으로 초기화 했는데 이것이 아닌 -1로 초기화해야한다.

   ```
   example1>
   2
   0 1
   output -> -1
   ```

2. 매번 dfs를 할 때 다음 숫자를 넣을 자리를 `그 전에 숫자 넣은 자리 + 1`이 아닌 `그 전 숫자 넣은 자리에서부터 처음으로 result의 값이 -1인 부분`이다. 처음에는 `그 전에 숫자 넣은 자리 + 1`로 구현하여서

   ```
   example2>
   4
   1 2 3 4
   output -> -1
   ```

   이라는 틀린 답이 나왔다.

   그래서 `그 전 숫자 넣은 자리에서부터 처음으로 result의 값이 -1이 부분`을 찾아서 위 예시대로 하니

   ```
   output ->2 3 4 2 1 3 1 4
   ```

   결과가 나와서 해결했다.



아래는 전체코드이다.

```python
# 숌 사이 수열
N = int(input())
data = list(map(int,input().split()))
data.sort()	# 문제 에서 답이 여러개일 경우 사전순으로 가장 빠른 것을 출력하라 했으니, 오름차순으로 정렬해서 dfs를 돌리면 가장 먼저 나온 정답이 사전순으로 가장 빠른 정답이라서 정렬함.
diction = {}	# 해당 숫자를 사용했는지 여부
for d in data:
    # diction[d] = 2
    diction[d] = diction.get(d,0) + 2

size = len(data) * 2
result = [-1] * size	# 정답을 담을 리스트

def dfs(total,length,index):	# total: 확인할 리스트, 현재 리스트에 넣은 숫자 개수, 현재 숫자 넣을 위치 인덱스
    if length == size:	# 인덱스가 끝까지 갔다는 것은 정상적으로 리스트를 만들었다는 의미이므로 True
        return True
    findIndex = index	# 현재 인덱스에 이미 숫자가 들어있을 수 있다. result안에 -1이 가장 가까운 인덱스로 이동.
    for d in data:
        while findIndex < size:
            if total[findIndex] == -1:
                break
            findIndex+=1
        if findIndex+d+1 < size and total[findIndex] == -1 and total[findIndex+d+1] == -1 and diction[d] != 0:	# 조건에 부합하면
			# 값 넣어주기
            total[findIndex] = d
            total[findIndex+d+1] = d
            diction[d] -= 2
            if dfs(total,length+2,index+1):	# dfs 결과가 True면 정답을 찾은거라서 종료
                return True
            # 복구
            total[findIndex] = -1
            total[findIndex + d + 1] = -1
            diction[d] += 2

    return False

if dfs(result,0,0):
    for r in result:
        print(r,end=' ')
else:
    print(-1)
```

