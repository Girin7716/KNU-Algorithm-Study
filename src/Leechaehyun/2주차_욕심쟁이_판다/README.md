# 욕심쟁이 판다

### 문제 유형
DFS + DP

DFS로 한 칸에서 갈 수 있는 최대로 진행해나가며, 더 이상 도달할 수 없는 지점에서부터 돌아오며 DP를 갱신한다.

즉, DP[i][j] = i행 j열에서 출발해 갈 수 있는 최대 칸 수

```c++
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> p;

pair<int, int> dir[4] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

int n, board[500][500], dp[500][500];

int dfs(int row, int col) {
	if (dp[row][col]) return dp[row][col];

	int ret = 1;
	for (int i = 0; i < 4; i++) {
		int newR = row + dir[i].first, newC = col + dir[i].second;
		if (newR < 0 || newR == n || newC < 0 || newC == n) continue;
		if (board[newR][newC] > board[row][col]) {
			ret = max(ret, dfs(newR, newC) + 1);
		}
	}

	return dp[row][col] = ret;
}

void init() {
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> board[i][j];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(NULL);

	init();
	int answer = 0;
	for (int i = 0; i < n * n; i++)
		answer = max(answer, dfs(i / n, i % n));
	printf("%d\n", answer);

	return 0;
}
```