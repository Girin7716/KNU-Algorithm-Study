# 낚시왕

### 문제 유형

구현


상어의 이동을 최대 O(R) 또는 O(C)에 구해야 시간 초과를 피할 수 있다.

상어의 이동은 위, 아래 방향인 경우 (R - 1) * 2, 좌, 우 방향인 경우 (C - 1) * 2 의 주기를 가지므로 (이 주기를 t라 하자)

실제로는 상어의 속력 vel에 대해 vel % t 만큼의 이동만 구현하면 된다.

또한 크기가 큰 상어가 작은 상어를 잡아먹기 때문에, 이동은 큰 상어부터 실행한다. 만약 작은 상어가 후순위로 이동해 도달한 위치에 이미 다른 상어가 존재한다면, 그 상어는 먹히게 된다.

수식 등을 이용해 상어의 이동 후 위치를 O(1)만에 구하는 방법도 있을 것 같은데 귀찮아서 패스함.

```c++
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;
typedef pair<int, int> p;
typedef struct shark {
	int row, col;
	int lev, dir, vel;
};

pair<int, int> dir[5] = { {0, 0}, {-1, 0}, {1, 0}, {0, 1}, {0, -1} };

int R, C, m;
int board[101][101], board_temp[101][101];
vector<shark> sharks;
bool catched[10001];

int reverse_dir(int d) {
	return d % 2 == 0 ? d - 1 : d + 1;
}

int catch_shark(int col) {
	for (int i = 1; i <= R; i++) {
		if (board[i][col]) {
			int num = board[i][col] - 1;
			board[i][col] = 0;
			catched[num] = true;
			return sharks[num].lev;
		}
	}
	return 0;
}

void shark_move(int num) {
	//num번 상어의 이동 후 위치를 구함
	int stand = sharks[num].dir < 3 ? R : C;

	//(stand - 1) * 2의 주기로 움직인다
	int diff = sharks[num].vel % ((stand - 1) * 2);

	for (int i = 0; i < diff; i++) {
		sharks[num].row += dir[sharks[num].dir].first;
		sharks[num].col += dir[sharks[num].dir].second;

		if (sharks[num].row > R || sharks[num].row < 1) {
			if(sharks[num].row > R) sharks[num].row--;
			else sharks[num].row++;
			sharks[num].dir = reverse_dir(sharks[num].dir);
			i--;
		}

		if(sharks[num].col > C || sharks[num].col < 1) {
			if (sharks[num].col > C) sharks[num].col--;
			else sharks[num].col++;
			sharks[num].dir = reverse_dir(sharks[num].dir);
			i--;
		}
	}
	//최종 위치를 배열에 저장
	if (board_temp[sharks[num].row][sharks[num].col]) {
        //이미 다른 상어가 있는 위치라면 먹힘
		catched[num] = true;
		return;
	}

	board_temp[sharks[num].row][sharks[num].col] = num + 1;
}

bool compare(shark a, shark b) {
	return a.lev > b.lev;
}

shark create_shark(int r, int c, int s, int d, int z) {
	shark temp;
	temp.row = r; temp.col = c; temp.vel = s;
	temp.dir = d; temp.lev = z;
	return temp;
}

void board_cpy() {
	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= C; j++)
			board[i][j] = board_temp[i][j];
}

void init() {
	int r, c, s, d, z;
	cin >> R >> C >> m;

	for (int i = 0; i < m; i++) {
		cin >> r >> c >> s >> d >> z;
		sharks.push_back(create_shark(r, c, s, d, z));
	}

	//크기가 큰 순으로 정렬
	sort(sharks.begin(), sharks.end(), compare);
	for (int i = 0; i < m; i++) {
		board[sharks[i].row][sharks[i].col] = i + 1;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(NULL);

	int answer = 0;
	init();
	for (int i = 1; i <= C; i++) {
		memset(board_temp, 0, sizeof(board_temp));
		answer += catch_shark(i);
		for (int j = 0; j < sharks.size(); j++) if(!catched[j]) shark_move(j);
		board_cpy();
	}
	printf("%d\n", answer);

	return 0;
}
```