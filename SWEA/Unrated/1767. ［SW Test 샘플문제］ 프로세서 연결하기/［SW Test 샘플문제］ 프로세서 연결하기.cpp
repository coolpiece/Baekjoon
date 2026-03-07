#include <bits/stdc++.h>
using namespace std;

int n, dr[] = { -1,1,0,0 }, dc[] = { 0,0,-1,1 }, cnt = 0, rst = INT_MAX;

void dfs(vector<vector<int>> &map, vector<pair<int, int>> core, int idx, int coreCnt, int len) {
	// 출력
	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < n; j++) {
	//		cout << map[i][j] << ' ';
	//	}
	//	cout << '\n';
	//}
	//cout << "***" << coreCnt << " " << len << "rst: " << cnt << " " << rst << "\n";

	if (idx == core.size()) {
		if (coreCnt > cnt) { // 최대 연결로 갱신.
			cnt = coreCnt;
			rst = len;
		}
		else if (coreCnt == cnt) rst = min(rst, len);
		return;
	}

	int r = core[idx].first, c = core[idx].second;
	for (int i = 0; i < 4; i++) { // 4방향 선택.
		int nr = r + dr[i], nc = c + dc[i], flag = 1;
		while (nr >= 0 && nr < n && nc >= 0 && nc < n) {
			if (map[nr][nc] != 0) { // 막힌 경우.
				flag = 0;
				break;
			}
			nr += dr[i], nc += dc[i]; // 다음으로 이동.
		}

		int addLen = 0;
		if (flag) { // 연결 가능.
			int j;
			switch (i) {
			case 0:
				addLen += r;
				j = r - 1;
				while (j >= 0) map[j--][c] = 2;
				break;
			case 1:
				addLen += n - r - 1;
				j = r + 1;
				while (j < n)map[j++][c] = 2;
				break;
			case 2:
				addLen += c;
				j = c - 1;
				while (j >= 0) map[r][j--] = 2;
				break;
			case 3:
				addLen += n - c - 1;
				j = c + 1;
				while (j < n)map[r][j++] = 2;
				break;
			}

			dfs(map, core, idx + 1, coreCnt + 1, len + addLen);

			switch (i) {
			case 0:
				j = r - 1;
				while (j >= 0) map[j--][c] = 0;
				break;
			case 1:
				j = r + 1;
				while (j < n)map[j++][c] = 0;
				break;
			case 2:
				j = c - 1;
				while (j >= 0) map[r][j--] = 0;
				break;
			case 3:
				j = c + 1;
				while (j < n)map[r][j++] = 0;
				break;
			}
		}
	}
	dfs(map, core, idx + 1, coreCnt, len); // 선택하지 않는 경우.
}

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> n;
		vector<vector<int>> v(n, vector<int>(n));
		vector<pair<int, int>> list;
		cnt = 0, rst = INT_MAX;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> v[i][j];
				if (v[i][j] == 1 && i > 0 && i < n - 1 && j>0 && j < n - 1) {
					list.push_back(make_pair(i, j));
				}
			}
		} // 입력.

		dfs(v, list, 0, 0, 0);
		cout << "#" << t << " " << rst << "\n";
	}
	return 0;
}