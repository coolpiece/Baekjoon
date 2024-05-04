#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, x, y, count = 0;
    cin >> n >> m;

    vector<string> v(n);
    bool visited[600][600] = {
        false,
    };

    for (int i = 0; i < n; i++) {
        string info;
        cin >> info;
        v[i] = info;
        if (info.find('I') != -1) {
            x = i;
            y = info.find('I');
        }
    }

    queue<pair<int, int>> q;
    q.push({x, y});
    while (!q.empty()) {
        x = q.front().first, y = q.front().second;
        char c = v[x][y];
        visited[x][y] = true;
        q.pop();
        if (c != 'X') {
            if (c == 'P') count++;
            if (x && !visited[x - 1][y]) {
                visited[x - 1][y] = true;
                q.push({x - 1, y});
            }
            if (y && !visited[x][y - 1]) {
                visited[x][y - 1] = true;
                q.push({x, y - 1});
            }
            if (y != v[0].size() - 1 && !visited[x][y + 1]) {
                visited[x][y + 1] = true;
                q.push({x, y + 1});
            }
            if (x != v.size() - 1 && !visited[x + 1][y]) {
                visited[x + 1][y] = true;
                q.push({x + 1, y});
            }
        }
    }
    if (count)
        cout << count;
    else
        cout << "TT";
}