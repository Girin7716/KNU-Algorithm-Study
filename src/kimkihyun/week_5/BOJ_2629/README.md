
# 양팔저울

## 풀이 방법

```python
def backtracking(result, depth):
if depth > N: return
if visited[depth][result]: return

visited[depth][result] = True

backtracking(result+sinker[depth],depth+1)
backtracking(abs(result-sinker[depth]),depth+1)
backtracking(result,depth+1
```
- 고려해야할 케이스는 총 3가지이다.
1. 추를 저울의 오른쪽에 올린 경우
2. 추를 저울의 왼쪽에 올린 경우
3. 추를 저울에 안올리 경우

dfs를 하면서 기저 케이스(올린 추의 개수가 총 추의 개수를 넘는경우, 이미 해당 무게를 알 수 있는 경우)에는 종료하고, 아닐 경우 해당 구슬의 수(이때, 구슬의 수란 저울에 올라간 총 구슬의 수가 아니고 검사한 구슬임)와 그때 알 수 있는 무게를 방문표시 해준다.

그러면 결국 마지막에는 검사한 구슬에서의 해당 값이 방문했는지 안했는지 알 수 있다.

`visited[N][marble]`

## 느낀점

- 백트래킹인거는 알았으나 어떻게 풀어야할지 몰라서 다른 분 답을 보고 최대한 이해할려고 노력했다.
- 백트래킹은 케이스를 정하고 이에대한 함수 호출을 알맞게 해주고 기저 설정을 잘하면 될듯.
- 백트래킹 연습좀 해야겠다.

