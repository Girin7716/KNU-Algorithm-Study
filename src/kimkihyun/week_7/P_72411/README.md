# 메뉴 리뉴얼

## 풀이 방법

입력으로 주어지는 orders를 길이 순으로 정렬을 해준다(이제보니까 할 필요 없는듯)

그 다음 입력으로 주어진 course의 원소만큼 orders의 원소에 combination을 구한다. 이때, order는 알파벳순으로 배치되어야한다. 그리고, 해당 combination을 key로 가지는 딕셔너리를 생성해서 개수를 count한다.
```python
order = ''.join(list(sorted(list(order))))
rems = list(combinations(order,c))
for rem in rems:
    comb[rem] = comb.get(rem,0) + 1
```

그 후, comb가 만약 빈 딕셔너리면 continue, 아닐 경우 max_value를 확인해서 1일경우 continue, 그 외의 경우는 max_value와 같은 값을 가지는 key를 answer에 추가해주면 된다.

</details>