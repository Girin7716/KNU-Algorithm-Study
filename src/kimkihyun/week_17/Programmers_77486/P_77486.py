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

print(solution(["john", "mary", "edward", "sam", "emily", "jaimie", "tod", "young"],
               ["-", "-", "mary", "edward", "mary", "mary", "jaimie", "edward"],
               ["young", "john", "tod", "emily", "mary"],
               [12, 4, 2, 5, 10]))

print(solution(["john", "mary", "edward", "sam", "emily", "jaimie", "tod", "young"],
               ["-", "-", "mary", "edward", "mary", "mary", "jaimie", "edward"],
               ["sam", "emily", "jaimie", "edward"],
               [2, 3, 5, 4]))