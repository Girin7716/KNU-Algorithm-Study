# Q16287


## 풀이 방법

A+B+C+D = w 가 되어야한다.

처음에는 그래서 단순하게 combinations을 이용해서 풀었으나 당연하게 시간초과가 발생했다.(왜냐하면 5000C4이기 때문..)(즉 4중 for문)

그 다음 생각한게 dp였으나 어떻게 풀어야하는지 감이 오지않아서 인터넷에 검색해서 풀이방법을 알아왔다.

A+B = w-C-D로 생각하여 4중 for문 -> 2중 for문으로 바꿔야한다.

로직은 아래와 같다.
```python
def check():
    for i in range(n):
        for j in range(i + 1, n):
            if parcel[i] + parcel[j] < w and dp[w - parcel[i] - parcel[j]]:
                return True
        for j in range(i):
            if parcel[i] + parcel[j] < w:
                dp[parcel[i] + parcel[j]] = True

    return False
```
- parcel을 앞에서부터 검사를한다.
- i와,i보다 큰 값들의 합을 구하고, `dp[w-parcel[i]-parcel[j]`가 True이면 이미 i보다 작은 인덱스의 값들의 합이 있었다는 의미이므로 'yes' 출력
- i번째의 값포함 이전까지 2개씩 뽑아내면서 두 무게의 합이 w 보다 작다면 해당 무게의 dp, 즉 `dp[parcel[i]+parcel[j]] < w`이면 True로 바꿔준다.
