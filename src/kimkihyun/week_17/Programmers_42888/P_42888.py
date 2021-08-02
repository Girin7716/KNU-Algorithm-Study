# 오픈채팅방
def solution(records):
    answer = []
    inOut = ["님이 들어왔습니다.","님이 나갔습니다."]
    nickname = {}   # key : value = uuid : nickname

    for record in records:
        splitRecord = record.split(' ')
        # movement,id,nickname = splitRecord[0],splitRecord[1],splitRecord[2]
        if splitRecord[0] == 'Enter':
            answer.append([splitRecord[1],0])
            nickname[splitRecord[1]] = splitRecord[2]
        elif splitRecord[0] == 'Leave':
            answer.append([splitRecord[1],1])
        elif splitRecord[0] == 'Change':
            nickname[splitRecord[1]] = splitRecord[2]

    for i in range(len(answer)):
        answer[i] = nickname[answer[i][0]]+inOut[answer[i][1]]

    return answer

print(solution(["Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"]))
