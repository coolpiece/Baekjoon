#include <bits/stdc++.h>
using namespace std;
void dfs(bool[][50], vector<string>, int, int);

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, count = 0;
    cin >> n >> m;
    vector<string> v;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        v.push_back(str);
    }

    bool visited[50][50] = {
        false,
    };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j]) {
                dfs(visited, v, i, j);
                count++;
            }
        }
    }
    cout << count;
}

void dfs(bool visited[][50], vector<string> v, int x, int y) {
    int m = v[0].size();  // 가로 길이
    int n = v.size();     // 세로 길이
    if (!visited[x][y]) {
        visited[x][y] = true;
        if (v[x][y] == '-') {  // 가로인 경우
            if (y <= m - 2) {
                if (v[x][y + 1] == '-') {
                    dfs(visited, v, x, y + 1);
                }
            }
        } else if (v[x][y] == '|') {  // 세로인 경우
            if (x <= n - 2) {
                if (v[x + 1][y] == '|') {
                    dfs(visited, v, x + 1, y);
                }
            }
        }
    }
}