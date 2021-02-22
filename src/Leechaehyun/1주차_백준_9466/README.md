# 텀 프로젝트

### 문제 유형

DFS

그래프 내에서 사이클을 찾고 그 크기를 계산하는 문제이다.

이를 계산하기 위해 최초 1번 노드부터 DFS로 방문하는 노드마다 방문 순서(코드의 ord)를 붙인다. 

만약 이미 방문한 노드에 도착했다면(visit이 true), 이전에 노드에 기록했던 ord값과 이번에 기록해야 할 ord값을 통해 사이클의 크기를 O(1)만에 구해낼 수 있다.

한 번의 DFS로 노드들을 탐색하다 사이클을 만나 탐색이 종료되었을 경우 아직 탐색하지 않은 노드부터 다시 DFS를 시작하는데, 다음부터의 DFS가 이전 DFS에서 방문된 점을 만날 시에는 절대로 사이클이 형성될 수 없다. 이를 구분하기 위해 코드에서 step 변수를 사용했음.

이 문제는 6달 전에 풀었다가 이번에 다시 풀어본 문제라 코드가 깔끔함

```c++
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;
typedef pair<int, int> p;

int n, ord = 1, cycle_size;
int visit[100001], conn[100001], cycle[100001];

void dfs(int node, int ord, int step) {
	visit[node] = ord;
	cycle[node] = step;

	int next = conn[node];
	if (visit[next]) {
		//사이클이 발생한 경우, 사이클의 크기를 구해 더함 (같은 step일 때만)
		if(cycle[next] == step) cycle_size += (ord - visit[next] + 1);
		return;
	}

	dfs(next, ord + 1, step);
}

void init() {
	cin >> n;
	memset(visit, 0, sizeof(visit));
	memset(conn, 0, sizeof(conn));

	for (int i = 1; i <= n; i++) cin >> conn[i];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(NULL);

	int tc;
	cin >> tc;

	for (int i = 0; i < tc; i++) {
		int step = 1;
		cycle_size = 0;
		init();
		for (int j = 1; j <= n; j++) 
			if (!visit[j]) { dfs(j, 1, step); step++; }
		printf("%d\n", n - cycle_size);
	}

	return 0;
}
```