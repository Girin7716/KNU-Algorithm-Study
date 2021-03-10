# ������

## Ǯ�� ���
��ü �ڵ�� �Ʒ��� ����.
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
���ʴ�� �� �̷��� �ڵ带 ����ߴ��� �м��غ����� �Ѵ�.

```python
tickets.sort(reverse=True)
```
- dictionary�� key : value �������� �Ǿ������� graph�� dictionary�� �����ϸ鼭 value�� ����Ʈ�� �־��ְ��� �ߴ�. value�� ����Ʈ�̹Ƿ� �ڿ������� stack ������ �ȴ�.
- tickets�� ������������ ������ ������ �������� ���� ���� ��ΰ� ���� �� ������ �� ��, ���ĺ� ������ �ռ��� ��θ� return�ϱ� �����̴�.
- ��, stack �������� pop()�� �� ��� ���� ���Ұ� �����µ� �̶�, ���ĺ��� �����͵���� pop()�� �ϰ� �;� sort(reverse=True)�� ���־���.

```python
graph = {}
for ticket in tickets:
    a, b = ticket
    graph[a] = graph.get(a,[])+[b]
```
- graph�� dictionary�� �����ϴ� �ڵ��̴�.
- ���⼭ `graph[a] = graph.get(a,[])+[b]`�� �ǹ̸� �� �ʿ䰡 �ִ�.(��ųʸ� �ͼ��������ҵ�)
- graph.get(key) : �ش� key������ value�� ��ȯ�Ѵ�.(���� �ش� key�� ���� ���� `NoneType`�� default�� ��ȯ.)
- graph.get(key,[]) : �ش� key�� ���� value�� ��ȯ�ϳ�, �ش� key�� ���� ��쿡�� `[]`�� ��ȯ�ϵ��� �Ѵ�.
- `graph.get(a,[]) + [b]` : a(key)�� ���� value�� ��ȯ(������ [] ��ȯ) �ű⿡ `[b]`�� ���Ͽ� �־��ش�.

```python
stack = ["ICN"]
while stack:
    now = stack[-1]
    if now not in graph or len(graph[now]) == 0:
        answer.append(stack.pop())
    else:
        stack.append(graph[now].pop())
```
- "ICN"���� ������ �����ؾ��ϴϱ� `stack = ["ICN"]`�� ���ش�.
- �� �� stack�� �̿��ؼ� DFS�� �����Ѵ�.
- ����� DFS�� ����ϳ� �ٸ� ���� ó���� stack�� pop�ϴ� ���� �ƴϰ� �ش� ������ ����(`now=stack[-1]`)�� �صд�.
- �� ��, �ش� ���� ���̻� �湮�� �� �� ���� ��� answer�� �ش� ���� �־��ְ� �ش� ���� stack���� pop���ش�.
  - �̷��� ǥ���� �ϱ� ���ؼ� `if now not in graph or len(graph[now]) == 0:`��� �ۼ���.
  - `now not in graph` -> now���� ����ؼ� �ٸ� ���� ���� ��찡 ���� ���
  - `len(graph[now]) == 0` -> now���� ����ؼ� �ٸ� ���� ���� ���� �־�����, �� �湮�� ����
- �� ���� ����, �ش� ��忡�� �ٸ� ������ �湮�� �� �ִٴ� �ǹ��̹Ƿ� stack�� �ش� ���� �־��ְ� graph dictionary���� �ش� ���� pop()���ش�.

```python
return answer[::-1]
```
- �̷��� �� ��� graph�� ���� �湮������, stack�� ���� pop�� ������ answer�� �׿������Ƿ� �̸� �������� ����ؾ� ���ϴ� ����� ���´�.



## ������
ó������ 
```
[["ICN", "SFO"], ["ICN", "ATL"], ["SFO", "ATL"], ["ATL","ICN"], ["ATL","SFO"]]
```
�̷������� �׷����� �־����淡 �翬�ϰ� dictionary�� �̿��Ͽ� graph�� �����ؾ߰ڴٰ� �����ߴ�. �׷��� ����Ž�� ������ dictionary�� Ǯ����� ���� ��� �ؾ����� �ظŴٰ� �ᱹ �ٸ� ������� Ǯ�̸� ���� �ذ��Ͽ��µ�, �̷��� ��� ���߿��� ������ ���Ƽ� ��õ ������ �÷ȴ�.

dictionary�� �ͼ��������� �ʿ䰡 ������ ����.