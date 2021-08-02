# 다단계 칫솔 판매

## 풀이방법

- 조직도를 dictionary(`tree`)로 구현.(key : value = 사람 : 소개시켜준 사람)

- 각 사람이 번 돈을 저장할 dictionary(`pay`) 구현(key:value = 사람 : 번 돈)

- 그 후, seller를 보면서, `people(돈을 번 사람)`에게는 `money - (int(money*0.1))`을 주고, `money`를 `int(money*0.1)`로 바꾸고,  `people`을 소개시켜 준 사람으로 바꾸면서, `people`이 `center`가 되거나, `money`가 == 0 이 될때 까지 반복을 하면서 돈을 더 해준다.

- 그러면 `pay` dictionary에는 root인 `center`를 포함한 번 돈들이 나오게된다.

- 그러면 `pay`에서 `center`를 없애버린뒤, `answer = list(pay.values())` 통해 list로 바꿔서 답을 도출한다.



아래는 전체 코드이다.

```python
# 다단계 칫솔 판매
def solution(enroll, referral, seller, amount):
    tree = {}
    pay = {'center':0}
    for i in range(len(enroll)):
        pay[enroll[i]] = 0
        if referral[i] == '-':
            tree[enroll[i]] = 'center'
        else:
            tree[enroll[i]] = referral[i]

    for i in range(len(seller)):
        money = amount[i] * 100
        people = seller[i]

        upMoney = int(money*0.1)
        pay[people] += money-upMoney
        money = upMoney
        people = tree[people]

        while people != 'center':
            upMoney = int(money * 0.1)
            pay[people] += money-upMoney

            people = tree[people]
            money = upMoney
            if money == 0:
                break

    pay.pop('center')
    answer = list(pay.values())

    return answer
```



