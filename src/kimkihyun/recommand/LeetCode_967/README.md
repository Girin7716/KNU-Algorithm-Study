# 967. Numbers With Same Consecutive Differences

## 추천 이유

알고 스터디원들이 LeetCode에서 코드 제출하는 방법을 알았으면 좋을 것 같았다.

그리고, 이 문제와 더불어 아래 주소의 문제도 풀어보면 좋을 것 같다.(이거는 문제를 풀어서 제출하는게 아님)
https://leetcode.com/discuss/interview-question/360770/Uber-or-Onsite-or-Jumping-Numbers



## 풀이 방법

문제에서는 `n`의 길이의 숫자들 중 (ex>n=3이면, 숫자 세자리(123,476,246,...)) 각 숫자들 옆의 숫자들의 차이가 `k`만큼 차이나는 숫자들을 찾아 정렬한 리스트를 반환하라고 한다.(단, 070과 같이 0으로 시작하는 숫자는 탐색 제외)

그리하여 떠오른 생각은 dfs를 통해 해당 조건을 만족하는 숫자들을 찾아 result에 넣어주는 것이다. 이때 첫번째 자리의 수의 후보군은 `1~9`이므로 이를 dfs를 통해 탐색을 하며 조건을 만족시키면 해당 수를 result에 넣어주면 된다. 1부터 차례대로 탐색하므로 result에 차례대로 조건을 만족시키는 값을 넣어주는 행위 자체가 오름차순으로 정렬될 것이다.



전체 코드는 아래와 같다.

```python
class Solution:
    def numsSameConsecDiff(self, n: int, k: int) -> List[int]:
        result = []
        def dfs(total,end,cnt):
            if cnt >= n:
                result.append(total)
                return

            for i in range(10):
                if abs(end-i) == k:
                    dfs((10*total) + i,i,cnt+1)

        for i in range(1,10):
            dfs(i,i,1)
        return result
```



차례대로 분석 해보겠다.



```python
def numsSameConsecDiff(self, n: int, k: int) -> List[int]:
```

- python에서 `-> List[int]:` 이걸 처음봤는데 그냥 명시적으로 적은거라고 한다.
- 즉, List안 원소들의 타입을 int로 해서 반환하라는 의미이다.



```python
result = []
for i in range(1,10):
    dfs(i,i,1)
return result
```

- `result `: 조건에 만족하는 숫자들을 담을 리스트
- `dfs(total, end, cnt)`
  - `total` : 현재 탐색하고 있는 숫자
  - `end` : 현재 탐색하고 있는 숫자의 제일 뒤에 있는 숫자(ex>total이 157이면 end는 7임)
  - `cnt` : 현재 탐색하는 숫자가 몇자리인지 알려줌(ex>total이 157이면 cnt는 3)
  - 1~9로 시작하는 모든 숫자를 탐색하기 위해서 dfs 돌린다.



```python
def dfs(total,end,cnt):
	if cnt >= n:	# 종료 조건, 이를 만족하면 조건에 total이 조건에 부합한거임.
    	result.append(total)
        return

	for i in range(10):
    	if abs(end-i) == k:	# 끝에있는 숫자와 뒤에 붙일 숫자의 차이가 k이면 조건 만족
        	dfs((10*total) + i,i,cnt+1)	# 기존 total에 조건을 만족하는 i를 붙이고, end는 i가되며, 자릿수가 하나 늘어남
```



## 느낀점

편안한 마음에서 풀어보니까 간단하면서도 깔끔하게 풀리는거 같다.

더 효율적인 방법이 있는지 궁금하다.(dp...?)