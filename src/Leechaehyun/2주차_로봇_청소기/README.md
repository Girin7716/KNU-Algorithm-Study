# 로봇 청소기

### 문제 유형

BFS, Bitmask

더러운 칸의 개수가 최대 10개이므로, 각 더러운 칸을 청소한 상태를 비트마스크로 나타낼 수 있다.

예를 들어, 총 5개의 더러운 칸 중 1, 4번째의 더러운 칸만 청소했다면 이는 01001 로 나타내는 게 가능하다.

이러한 비트마스킹은 인덱싱에 아주 유리하다. 따라서 visit 배열을 visit[state][row][col]의 형태로 선언한다.

visit[01001][2][3] : 1, 4번째 더러운 칸을 청소한 상태에서 2행 3열에 위치.

핵심은 동일한 state에서 동일한 칸을 다시 방문할 필요가 없다는 것이다.

```c++
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <memory.h>

using namespace std;
typedef pair<int, int> p;
typedef pair<p, p> pp;

pair<int, int> dir[4] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

int r, c, board[20][20], fullstate;
bool visit[1 << 10][20][20];
p startpos;

int bfs() {
	queue<pp> que;
	que.push({ {0, 0}, startpos });
	visit[0][startpos.first][startpos.second] = true;

	while (!que.empty()) {
		pp cur = que.front();
		que.pop();

		int state = cur.first.first;
		int cnt = cur.first.second;
		int row = cur.second.first;
		int col = cur.second.second;

		if (state == fullstate) return cnt;

		for (int i = 0; i < 4; i++) {
			int newR = row + dir[i].first;
			int newC = col + dir[i].second;

			if (newR == r || newR < 0 || newC == c || newC < 0) continue;
			if (board[newR][newC] == -1) continue;
			int newState = state;
			if (board[newR][newC] > 0) newState |= (1 << (board[newR][newC] - 1));

			if (visit[newState][newR][newC]) continue;
			visit[newState][newR][newC] = true;
			que.push({ {newState, cnt + 1},  {newR, newC} });
		}
	}
	return -1;
}

void init() {
	string input;
	int numbering = 1;
	cin >> c >> r;

	memset(board, 0, sizeof(board));
	memset(visit, 0, sizeof(visit));

	for (int i = 0; i < r; i++) {
		cin >> input;
		for (int j = 0; j < c; j++) {
			if (input[j] == 'x') board[i][j] = -1;
			if (input[j] == '*') board[i][j] = numbering++;
			if (input[j] == 'o') startpos = { i, j };
		}
	}
	fullstate = (1 << (numbering - 1)) - 1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(NULL);

	while(1) {
		init();
		if (r == 0 && c == 0) break;
		printf("%d\n", bfs());
	}

	return 0;
}
```