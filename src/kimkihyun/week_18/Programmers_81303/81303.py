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

print(solution(8,2,["D 2","C","U 3","C","D 4","C","U 2","Z","Z"]))
print(solution(8,2,["D 2","C","U 3","C","D 4","C","U 2","Z","Z","U 1","C"]))