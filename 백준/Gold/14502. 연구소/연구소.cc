/*
1. 입력 받으면서 빈칸, 바이러스 위치 별도로 저장.
	바이러스: 확산해야하므로 큐에 저장.
	빈칸: 조합으로 선택해야하므로 벡터에 저장.

2. 조합으로 3칸 선택, 벽 세우기
3. 바이러스 퍼지는 시뮬레이션 수행
4. 안전 영역 크기 계산

위 2~4단계 반복.
*/

#include<bits/stdc++.h>
using namespace std;

struct Cell {
	int r, c;
	Cell(int r, int c) : r(r), c(c) {}
};

void combi(vector<vector<int>>&, int, int);
int virus(vector<vector<int>>&);

vector<Cell> blank; // 빈칸 위치 저장.
queue<Cell> virusPos; // 바이러스 위치 저장.

int dr[] = { -1, 1, 0, 0 }, dc[] = { 0, 0, -1, 1 }, n, m, maxVal = 0;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	vector<vector<int>> board(n, vector<int>(m));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 0)
				blank.emplace_back(i, j);
			else if (board[i][j] == 2)
				virusPos.emplace(i, j);
		}
	}
	combi(board, 0, 0);
	cout << maxVal;
}

// 수정: combi 함수에서는 board를 사용하지 않음. (virus 함수로 전달하기 용.)
// -> 값으로 전달하는 대신 참조(&)를 전달하고, virus 함수 내에서 board를 복사하여 사용.
void combi(vector<vector<int>> &board, int start, int cnt) {
	if (cnt == 3) {
		maxVal = max(maxVal, virus(board));
		return;
	}

	for (int i = start; i < blank.size(); i++) {
		board[blank[i].r][blank[i].c] = 1;
		combi(board, i + 1, cnt + 1);
		board[blank[i].r][blank[i].c] = 0; // 되돌리기.
	}
}

int virus(vector<vector<int>> &originBoard) {
	vector<vector<int>> board = originBoard; // 넘겨 받은 원본 board를 복사하여 사용.
	queue<Cell> q = virusPos;
	int blankCnt = blank.size() - 3;

	while (!q.empty()) { // 바이러스 확산.
		Cell cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nr = cur.r + dr[i], nc = cur.c + dc[i];
			if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
			if (board[nr][nc] != 0) continue;
			board[nr][nc] = 2;
			blankCnt--;

			// 빈칸의 수가 지금까지 구한 최대 안전 영역크기보다 작으면 가지치기.
			if (blankCnt <= maxVal) return 0;

			q.emplace(nr, nc);
		}
	}
	return blankCnt;
}