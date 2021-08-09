# 표 편집

처음에는 disjoint set으로 문제를 풀어볼려고 했으나 실패가 자꾸 발생했다. 그래서 풀이방법을 바꿔서 dictionary를 doubly linked list 처럼 구현하여 문제를 해결했다.

## 풀이방법

`diction` : `표` 역할

- key : value = 고정된 행 번호 : [앞에 연결된 번호, 뒤에 연결된 번호]

`nowPtr` : 현재 가르키고 있는 행 번호

`restoreStack` : 행을 삭제했을때 복구하기 위한 스택

`command`

- `U X`
  - `X` 만큼 `diction`에서 앞에 연결된 번호로 이동
- `D X`
  - `X` 만큼 `diction`에서 뒤에 연결된 번호로 이동
- `C`
  - `nowPtr`에서 앞 뒤로 연결된 번호를 확인하고, `nowPtr` 번호를 restoreStack에 저장하고, answer에 `nowPtr`번째 원소를 `X`로 변경.
  - 근데 여기서 삭제하는 행이 제일 앞인지, 제일 뒤인지에 따라 로직이 달라지므로 따로 처리함.
- `Z`
  - restoreStack에서 원소를 꺼내서 복구한 뒤, 해당 번호번째 answer 값을 `O`로 변경
  - 그리고, 복구한 행이 제일 앞인지 제일 뒤인지 따라 다르게 처리함.



아래는 전체 코드이다.

```python
# 표 편집
def solution(n, k, command):
    answer = ["O" for i in range(n)]
    diction = {}
    for i in range(n):
        diction[i] = [i-1,i+1]
    nowPtr = k
    restoreStack = []

    for cmd in command:
        if cmd[0] == 'U':
            for i in range(int(cmd[2:])):
                nowPtr = diction[nowPtr][0]
        elif cmd[0] == 'D':
            for i in range(int(cmd[2:])):
                nowPtr = diction[nowPtr][1]
        elif cmd[0] == 'C':
            pre = diction[nowPtr][0]
            post = diction[nowPtr][1]
            restoreStack.append(nowPtr)
            answer[nowPtr] = 'X'

            if pre == -1:
                diction[post][0] = -1
                nowPtr = post
            elif post == n:
                diction[pre][1] = n
                nowPtr = pre
            else:
                diction[pre][1] = post
                diction[post][0] = pre
                nowPtr = post
        elif cmd[0] == 'Z':
            restoreElement = restoreStack.pop()
            answer[restoreElement] = 'O'
            pre = diction[restoreElement][0]
            post = diction[restoreElement][1]
            if pre != -1: diction[pre][1] = restoreElement
            if post != n: diction[post][0] = restoreElement

    return ''.join(answer)
```

