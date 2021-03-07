# 학교 탐방하기

## 풀이 방법

문제를 보고 Spanning Tree를 구하는 문제인 것을 알아챘다.

문제에서 아래와 같은 말이 있다.

>최악, 최선의 경로 간 피로도의 차이를 계산...

그러므로, maximum spanning tree와 minimum spanning tree를 둘 다 구해서 각각의 tree에서 오르막길의 개수를 파악한다. 이때, 입구에서 1번은 무조건 연결이므로 input으로 edges를 받을때 이를 제외하고 입구->1번의 cost를 저장해서 나중에 계산 로직에 포함한다.

input으로 값을 저장할때 오르막이 0, 내리막이 1이므로 나중에 편하게 계산하기위해 오르막:1,내리막:0으로 바꿔 저장했다.

minimum spanning tree는 edges를 cost 기준 오름차순으로 정렬하여 크루스칼 알고리즘으로 계산했다.

maximum spannig tree는 edges를 cost 기준 내림차순으로 정렬하여 크루스칼 알고리즘으로 계산했다.

```python
minst = minist()
min_fatigue = (minst+rem)**2
maxst = maxist()
max_fatigue = (maxst+rem)**2
print(max_fatigue - min_fatigue)
```

## 인증

![13418](./13418.JPG)