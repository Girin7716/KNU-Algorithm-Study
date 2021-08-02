# 오픈 채팅방

## 풀이방법

- 주어진 `records`를 `' '` 기준으로 split해준다. ( == `splitRecord`)
- `splitRecord`의 첫번째 원소에는 `Enter`,`Leave`,`Change`가 있다.
  - `Enter`일 경우, 
    - answer에 [uuid,0]를 넣어준다(uuid == `splitRecord[1]`, 0은 입장했다는 의미)
    - nickname dictionary에 key로 uuid를, valye로는 `splitRecord[2]`(닉네임)을 넣어준다.
  - `Leave`일 경우, 
    - answer에 [uuid,1]를 넣어준다(uuid == `splitRecord[1]`, 1은 퇴장했다는 의미)
  - `Chagne`일 경우,
    - nickname dictionary에 key로 uuid를, valye로는 `splitRecord[2]`(닉네임)을 넣어준다.
- 그러면 `answer`에는 `[[uuid,0],[uuuid,1],...]`의 형식으로 정보가 저장되어있고, 이를 하나씩 살펴보면서 형식에 맞춰서 바꿔주면 된다.
- 이때, uuid는 nickname dictionary에 value로 닉네임이 있기때문에 닉네임이 자동으로 업데이트 되어있다.



아래는 전체 코드이다.

```python
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
```

