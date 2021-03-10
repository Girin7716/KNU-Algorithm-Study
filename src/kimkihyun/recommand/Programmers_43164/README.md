# 여행경로

## 풀이 방법
전체 코드는 아래와 같다.
```python
def solution(tickets):
    answer = []
    tickets.sort(reverse=True)
    graph = {}
    for ticket in tickets:
        a, b = ticket
        graph[a] = graph.get(a,[])+[b]

    stack = ["ICN"]
    while stack:
        now = stack[-1]
        if now not in graph or len(graph[now]) == 0:
            answer.append(stack.pop())
        else:
            stack.append(graph[now].pop())
            
    return answer[::-1]
```
차례대로 왜 이러한 코드를 사용했는지 분석해보고자 한다.

```python
tickets.sort(reverse=True)
```
- dictionary는 key : value 형식으로 되어있으며 graph를 dictionary로 구현하면서 value는 리스트로 넣어주고자 했다. value가 리스트이므로 자연스럽게 stack 구조가 된다.
- tickets을 내림차순으로 정렬한 이유는 문제에서 여러 가지 경로가 나올 수 있지만 그 중, 알파벳 순서가 앞서는 경로를 return하기 때문이다.
- 즉, stack 구조에서 pop()을 할 경우 뒤의 원소가 나오는데 이때, 알파벳이 빠른것들부터 pop()을 하고 싶어 sort(reverse=True)를 해주었다.

```python
graph = {}
for ticket in tickets:
    a, b = ticket
    graph[a] = graph.get(a,[])+[b]
```
- graph를 dictionary로 형성하는 코드이다.
- 여기서 `graph[a] = graph.get(a,[])+[b]`의 의미를 알 필요가 있다.(딕셔너리 익숙해져야할듯)
- graph.get(key) : 해당 key에대한 value를 반환한다.(만약 해당 key가 없을 경우는 `NoneType`을 default로 반환.)
- graph.get(key,[]) : 해당 key에 대한 value를 반환하나, 해당 key가 없을 경우에는 `[]`를 반환하도록 한다.
- `graph.get(a,[]) + [b]` : a(key)에 대한 value를 반환(없으면 [] 반환) 거기에 `[b]`를 더하여 넣어준다.

```python
stack = ["ICN"]
while stack:
    now = stack[-1]
    if now not in graph or len(graph[now]) == 0:
        answer.append(stack.pop())
    else:
        stack.append(graph[now].pop())
```
- "ICN"부터 무조건 시작해야하니까 `stack = ["ICN"]`을 해준다.
- 그 후 stack을 이용해서 DFS를 수행한다.
- 평범한 DFS와 비슷하나 다른 점은 처음에 stack을 pop하는 것이 아니고 해당 변수를 저장(`now=stack[-1]`)만 해둔다.
- 그 후, 해당 값이 더이상 방문을 할 수 없는 경우 answer에 해당 값을 넣어주고 해당 값을 stack에서 pop해준다.
  - 이러한 표현을 하기 위해서 `if now not in graph or len(graph[now]) == 0:`라고 작성함.
  - `now not in graph` -> now에서 출발해서 다른 곳에 가는 경우가 없는 경우
  - `len(graph[now]) == 0` -> now에서 출발해서 다른 곳에 가는 경우는 있었지만, 다 방문한 상태
- 그 외의 경우는, 해당 노드에서 다른 곳으로 방문할 수 있다는 의미이므로 stack에 해당 값을 넣어주고 graph dictionary에는 해당 값을 pop()해준다.

```python
return answer[::-1]
```
- 이렇게 할 경우 graph를 전부 방문했을시, stack의 값을 pop한 값들이 answer에 쌓여있으므로 이를 역순으로 출력해야 원하는 출력이 나온다.



## 느낀점
처음에는 
```
[["ICN", "SFO"], ["ICN", "ATL"], ["SFO", "ATL"], ["ATL","ICN"], ["ATL","SFO"]]
```
이런식으로 그래프가 주어지길래 당연하게 dictionary를 이용하여 graph를 형성해야겠다고 생각했다. 그러나 완점탐색 문제를 dictionary로 풀어본적이 없어 어떻게 해야할지 해매다가 결국 다른 사람들의 풀이를 보고 해결하였는데, 이러한 사고가 나중에도 좋을거 같아서 추천 문제에 올렸다.

dictionary에 익숙해져야할 필요가 있을거 같다.