# 소수의 연속합

### 문제 유형

정수론, 에라토스테네스의 체, 투 포인터 알고리즘


N이 최대 400만이므로, eratos를 이용해 소수들을 골라낼 때 2000(sqrt(4000000))까지의 수만 사용하면 된다. 이를 통해 1 ~ 4000000까지의 모든 소수들을 저장한다.

이제 연속합으로 N을 만들기 위해 투 포인터 알고리즘을 사용한다.

1. 우선 N 이상이 될 때까지 소수들을 차례로 더한다. (오름차순으로)

2. N 이상에 도달했다면, 처음 수를 가리키는 lp 포인터와 마지막으로 사용된 소수의 다음 수를 가리키는 rp 포인터를 둔다.

3. 현재까지 구한 부분합을 cur라 할 때, 다음 과정을 반복한다.

* cur가 N보다 작다면, rp가 가리키는 소수 하나를 더한 뒤 rp를 1 증가시킨다.
* cur가 N보다 작아질 때까지 lp가 가리키는 소수 하나를 뺀 뒤, lp를 1 증가시킨다.
* 위 과정에서 cur이 N과 같아지는 경우 정답을 1 증가시킨다.


투 포인터 알고리즘을 사용하면 모든 부분합을 체크하는 데 O(N)의 시간복잡도가 필요해 문제의 시간 제한을 충족할 수 있다.

```c++
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define MAXSIZE 4000000

using namespace std;
typedef pair<int, int> p;

int n;
bool arr[4000001];
vector<int> primes;

void eratos() {
	for (int i = 2; i <= 2000; i++) {
		int v = i;
		for (int j = v * 2; j <= MAXSIZE; j += v) arr[j] = true;
	}

	for (int i = 2; i <= MAXSIZE; i++)
		if (!arr[i]) primes.push_back(i);
}

int get_answer() {
	//투포인터 알고리즘 사용
	int lp = 0, rp = 0, cur = 0, idx = 0, ret = 0;
	//n 이상이 될 때까지 소수들을 차례로 더함
	while (cur < n && idx < primes.size()) cur += primes[idx++];

	rp = idx;
	while (lp < rp && rp < primes.size()) {
		//rp가 가리키는 값을 먼저 더함 (반드시 n 이상이 됨)
		if(cur <  n) cur += primes[rp++];		
		//lp가 가리키는 값을 뺌(작은 순서대로 빼짐)
		while (cur >= n) {
			if (cur == n) ret++;
			cur -= primes[lp++];
		}
	}

	return ret;
}

void init() {
	cin >> n;
	eratos();
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(NULL);

	init();
	if (n == 2 || n == 3) printf("1\n");
	else printf("%d\n", get_answer());

	return 0;
}
```