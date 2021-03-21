# 순위 검색



## 풀이 방법

문제에 정확성을 요구하는 점에서 일단 이진탐색과 dictionary를 떠올렸다.

그리고 언어,직군,경력,소울푸드의 경우의 수가 별로 없어서 이에 대한 모든 경우의 수를 dictionary의 key로 넣어주었다.
```python
dict_keys(['jbjp', 'jbjc', 'jbj-', 'jbsp', 'jbsc', 'jbs-', 'jb-p', 'jb-c', 'jb--', 'jfjp', 'jfjc', 'jfj-', 'jfsp', 'jfsc', 'jfs-', 'jf-p', 'jf-c', 'jf--', 'j-jp', 'j-jc', 'j-j-', 'j-sp', 'j-sc', 'j-s-', 'j--p', 'j--c', 'j---', 'pbjp', 'pbjc', 'pbj-', 'pbsp', 'pbsc', 'pbs-', 'pb-p', 'pb-c', 'pb--', 'pfjp', 'pfjc', 'pfj-', 'pfsp', 'pfsc', 'pfs-', 'pf-p', 'pf-c', 'pf--', 'p-jp', 'p-jc', 'p-j-', 'p-sp', 'p-sc', 'p-s-', 'p--p', 'p--c', 'p---', 'cbjp', 'cbjc', 'cbj-', 'cbsp', 'cbsc', 'cbs-', 'cb-p', 'cb-c', 'cb--', 'cfjp', 'cfjc', 'cfj-', 'cfsp', 'cfsc', 'cfs-', 'cf-p', 'cf-c', 'cf--', 'c-jp', 'c-jc', 'c-j-', 'c-sp', 'c-sc', 'c-s-', 'c--p', 'c--c', 'c---', '-bjp', '-bjc', '-bj-', '-bsp', '-bsc', '-bs-', '-b-p', '-b-c', '-b--', '-fjp', '-fjc', '-fj-', '-fsp', '-fsc', '-fs-', '-f-p', '-f-c', '-f--', '--jp', '--jc', '--j-', '--sp', '--sc', '--s-', '---p', '---c', '----'])
```
- 이때

```python
rem = [['j','p','c','-'],['b','f','-'],['j','s','-'],['p','c','-']]
for x in list(product(*rem)):
    info_dict[''.join(x)] = []
```

이런식으로 코드를 구현했으며, 오랜만에 product를 사용해서 정리노트를 보고 사용하는걸 참고했다.

그 후, 입력으로 주어진 infos를 위와 같은 형태로 바꾸고 총 16가지 경우로 '-'를 대치한 문자를 key로 넣어주고 점수를 value로 넣어주었다.

```python
for info in infos:
    rem = info.split()
    string = ''
    for i in range(5):
        if i == 4:
            for k in range(5):
                for j in combinations(range(1,5),k):
                    temp = list(string)
                    for x in j:
                        temp[x-1] = '-'
                    info_dict[''.join(temp)].append(int(rem[i]))
        string+=rem[i][0]
```

그러면 key에 해당하는 점수들이 나열되어있는데 이를 이진탐색으로 개수를 파악하기 위해서 오름차순으로 sorting해주었다.

```python
for key in info_dict.keys():
    info_dict[key].sort()
```
마지막으로, 입력으로 주어진 query로 위와 같이 전처리 후, 해당 key에 해당하는 (value 리스트 길이 - query에서 주어진 점수)를 answer에 추가해주면 된다.

```python
for qry in query:
    temp = qry.split(' and ')
    temp = temp[:3] + temp[3].split()
    score = temp[4]
    string = ''
    for i in range(4):
        string+=temp[i][0]
    answer.append(len(info_dict[string])-bisect_left(info_dict[string],int(score)))
```


## 느낀점

1. dictionary를 활용하는 법에 익숙해지자.
2. combination, products 사용법에 익숙해지자.

