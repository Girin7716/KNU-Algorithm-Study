# 2048(Easy)

### 문제 유형

구현

각 블록들이 합쳐지는 것을 잘 구현하기만 하면 되는 문제임

좀 많이 예전에 2048 하드 풀면서 짠 코드라 깔끔하지 못함 추후에 다시 짜서 수정하겠음

```c++
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <memory.h>

using namespace std;

int n, maxval[11], answer = 0;
int board_origin[22][22];
int visit[22][22];
pair<int, int> d[4] = { {1, 0}, {0, -1}, {-1, 0}, {0, 1} };


void compress(int(*board)[22], int row, int col, int dir) {
	memset(visit, 0, sizeof(visit));
	//한 줄 압축
	for (int i = 2; i <= n; i++) {
		int curR = row + d[dir].first * (i - 1), curC = col + d[dir].second * (i - 1);
		if (board[curR][curC] == 0) continue;

		int newR = curR - d[dir].first, newC = curC - d[dir].second;
		while (board[newR][newC] == 0) {
			if (newR < 1 || newR >n || newC < 1 || newC > n) break;
			newR -= d[dir].first;
			newC -= d[dir].second;
		}

		if (!visit[newR][newC] && board[curR][curC] == board[newR][newC]) { 
			board[newR][newC] *= 2; board[curR][curC] = 0;
			visit[newR][newC] = true;
		}
		else {
			int temp = board[curR][curC];
			board[curR][curC] = 0;
			board[newR + d[dir].first][newC + d[dir].second] = temp;
		}
	}
}

void move(int(*board)[22], int dir) {
	//dir : 0123-NESW
	int row, col;
	switch (dir) {
	case 0: row = 1; col = 1; break;
	case 1: row = 1; col = n; break;
	case 2: row = n; col = 1; break;
	case 3: row = 1; col = 1; break;
	}

	if (dir == 0 || dir == 2) {
		for (int i = 1; i <= n; i++) compress(board, row, i, dir);
	}
	else
		for (int i = 1; i <= n; i++) compress(board, i, col, dir);
}

void printboard() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			printf("%4d ", board_origin[i][j]);
		printf("\n");
	}
	printf("---------------------\n");
}

void cpy(int(*dest)[22], int(*source)[22]) {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			*(dest[i] + j) = *(source[i] + j);
}

bool cmp(int(*dest)[22], int(*source)[22]) {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (*(dest[i] + j) != *(source[i] + j)) return false;
	return true;
}

int getmax(int(*board)[22]) {
	int retval = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (board[i][j] > retval) retval = board[i][j];
	return retval;
}

void dfs(int(*board)[22], int cnt) {
	//가지치기
	//현재 cnt에서 구할 수 있는 최댓값에 도달하지 못한 경우 가지치기
	//printf("--------------\n");
	int curmax = getmax(board);
	//printf("curmax : %d, cnt : %d\n", curmax, cnt);
	if (maxval[cnt] > curmax) return;
	//printboard();

	//10회 모두 이동했다면 종료
	if (cnt == 5) {
		/*while (cnt > 0) {
			answer = answer < curmax ? curmax : answer;
			int v = answer;
			maxval[cnt--] = v;
			v /= 2;}*/
		if (curmax > answer) answer = curmax;
		return;
	}

	//변경 전 배열 저장
	int cache[22][22];
	cpy(cache, board);

	//4방향으로 블록을 이동시킨 각각의 분기마다 재귀실행
	for (int i = 0; i < 4; i++) {
		move(board, i);
		//변경 전후로 판에 변화가 없다면 재귀실행하지 않음
		if (!cmp(board, cache)) {
			dfs(board, cnt + 1);
		}
		cpy(board, cache);
	}
	return;
}

void init() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			scanf("%d", &board_origin[i][j]);
		}
	
}

int main() {
	init();
	int dir;
	//printboard();
	answer = getmax(board_origin);
	dfs(board_origin, 0);
	printf("%d\n", answer);
	return 0;
}

```