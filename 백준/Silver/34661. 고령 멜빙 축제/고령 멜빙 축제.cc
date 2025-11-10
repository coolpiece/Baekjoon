#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> v(101, vector<int>(101));

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int T = 0; T < t; T++) {
        int n, m, cnt = 0;
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                char c;
                cin >> c;
                if (c == '.') {
                    v[i][j] = 0;
                    cnt++;
                } else
                    v[i][j] = 1;  // 장애물.
            }
        }

        if (cnt % 2)
            cout << "sewon\n";
        else
            cout << "pizza\n";
    }
}