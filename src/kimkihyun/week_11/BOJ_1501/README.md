# 영어 읽기

문제를 보고 사전에 등록할 단어를 중첩 딕셔너리로 구성하면 되겠다라고 생각했다.

그런데, 여기서 내가 생각치못한 케이스들이 있다.

1. M개의 줄에는 `문장`이 온다. 즉, 백준의 예시1처럼 `단어`가 올 수도 있지만, 아래처럼 `문장`이 들어올 수도 있다. 문장이 오면 공백을 기준 단어를 파악해야한다.

   ```
   10
   It
   is
   interesting
   that
   people
   can
   read
   some
   grabled
   words
   1
   It is itnersetnig taht pepole can raed smoe grabeld wrods.
   ```

2. 아래에서 설명하겠지만, 중첩 딕셔너리 구조를 나는 `[처음알파벳마지막알파벳][그외 가운데 알파벳들]` 의 key로 구성을했다. 그러나, 사전에 `a`나 `aa`와 같이 들어오면 실패하므로 예외처리를 해줘야한다.

   ```
   6
   a
   b
   aa
   ababa
   aabba
   abcaa
   4
   a
   aa
   ababa
   abbaa
   ```

3. `영어 문장이 주어졌을 때, 그 문장을 해석하는 방법의 경우의 수를 구하는 프로그램을 작성하시오` 라고 문제에 적혀있다. 여기서 경우의 수를 구해야하므로 만약 `It is interesting that people`인데, 예를들어 (It->1개, is->1개, interesting -> 4개, that -> 2개, people -> 3개)일 경우 경우의 수는 `1*1*4*2*3 = 24`이다.



이러한 점을 생각하고 풀면된다.



## 풀이방법

```python
# 영어 읽기
N = int(input())
diction = {}
for _ in range(N):
    data = input()
    # 길이가 1 (ex>a,b,c,...)이면, 알파벳의 시작과 끝은 data 그 자체이고, 그 사이 알파벳은 없다.
    if len(data) == 1:
        startEnd = data
        mid = []
    # 그 외에는 startEnd가 존재하며, mid는 그외 알파벳들이다. 이때, mid도 key로 사용할 예정이니 sort해준다.
    else:
        startEnd = data[0]+data[-1]
        mid = list(data[1:len(data)-1])
        mid.sort()
    # key로 사용할거니까 list대신 str로 바꾸기
    mid = str(mid)

    # 만약 dictionary에 startEnd라는 Key가 있다면
    if diction.get(startEnd):
        # diction[startEnd]안 key로 mid가 있다면 +1 해서 개수 늘려주기
        if diction[startEnd].get(mid):
            diction[startEnd][mid] += 1
        # 없다면 생성
        else:
            diction[startEnd][mid] = 1
    # dictionary에 startEnd라는 Key가 없으면, mid를 key로 가지고 1을 value로 가지는 key 생성.
    else:
        diction[startEnd] = {mid : 1}

M = int(input())
for _ in range(M):
    answer = 1
    sentence = input()
    # 위와 똑같이 해주되, 문장이 들어오므로 공백기준으로 잘라서 경우의 수 파악
    for data in sentence.split():
        if len(data) == 1:
            startEnd = data
            mid = []
        else:
            startEnd = data[0] + data[-1]
            mid = list(data[1:len(data) - 1])
            mid.sort()
        mid = str(mid)
        if diction.get(startEnd):
            if diction[startEnd].get(mid):
                # diction[startEnd][mid]에는 매칭되는 횟수가 나오므로 경우의 수를 구하기 위해서 answer에 곱해준다.
                answer *= diction[startEnd][mid]
            else:
                # 근데 매칭되는게 없으면 문장을 결정 못하므로 0
                answer = 0
        else:
            # 근데 매칭되는게 없으면 문장을 결정 못하므로 0
            answer = 0

    print(answer)
```



## 느낀점

처음보고는 솔직히 쉽다고 생각했는데, 예상치못한 곳에서 자꾸 예외가 발생했다...

문제를 꼼꼼히 읽어야 할 듯....