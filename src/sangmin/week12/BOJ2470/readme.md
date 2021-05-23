<meta name='type' content ='투포인터'>
<meta name='BOJ' content='BOJ270'>
<meta name='difficulty' content='gold5'>
<meta name='url' content='https://www.acmicpc.net/problem/2470'>
<meat name='date' cotent='2021-05-22'>

1. 코드 설명

<hr>

[용액](https://www.acmicpc.net/problem/2467) 문제에 정렬만 추가하면 된다.

아래는 [용액](https://www.acmicpc.net/problem/2467)에 대한 나의 풀이이다.

투 포인터를 이용하여 두 값을 더했을때 절대값이 가장 작은 문제를 구하는 코드이다.

투 포인터를 사용하는 전형적인 문제이다.

left를 0번 idx로, right를 N-1번째 idx로 정한다.

그렇다면 전부다 알칼리거나 전부다 산성이 아닌 이상(전부다 동일해도 상관없다. 쉬운 이해를 위해 가정)

left는 알칼리, right는 산성이 될것이다. 알칼리와 산성을 더했더니 만약 산성쪽에 더 가깝다면 알칼리를 더 넣는것이 아닌 산성쪽을 덜 넣어야 할것이다.

이는 알칼리도 마찬가지이다.

두 값을 더했더니 0 보다 크면 산성이기 때문에 right를 줄여주고,

0 보다 작다면 알칼리이기 때문에 left를 증가시켜 준다.

```cpp
    if(sum > 0) right--;
    else left++;
```

이렇게 두 값을 더해가면서 left가 right 보다 작을동안.

더한 값의 절대값이 가장 작은 idx를 구해주면 된다.

2. 느낀점

<hr>

처음에는 dp로 해결하는 문제인가 싶었지만 다행히 2가지 용액이기 때문에 투 포인터로 해결하면 될것이라 생각했다.

하지만 중간중간 문제점은 용액의 농도가 매우 크기 때문에 long long int로 자료형을 지정해주어야 해결할수 있었다.