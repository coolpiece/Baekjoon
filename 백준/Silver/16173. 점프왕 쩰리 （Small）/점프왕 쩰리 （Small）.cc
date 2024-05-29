#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x = 0, y = 0;
    cin >> n;
    int m[n][n];
    bool visited[n][n] = {
        false,
    };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> m[i][j];
        }
    }

    queue<pair<int, int>> q;
    q.push({0, 0});
    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        int move = m[x][y];
        q.pop();
        visited[x][y] = true;
        if (x + move <= n - 1) {
            if (m[x + move][y] == -1) {
                cout << "HaruHaru";
                exit(0);
            }
            else if(!visited[x + move][y]) q.push({x + move, y});
        }
        if (y + move <= n - 1) {
            if (m[x][y+move] == -1) {
                cout << "HaruHaru";
                exit(0);
            }
            else if (!visited[x + move][y]) q.push({x, y + move});
        }
    }
    cout << "Hing";
}