#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, cnt = 0;
    cin >> N >> M;
    vector<vector<int>> v(100, vector<int>(100));
    for (int i = 0; i < 100; i++)
        for (int j = 0; j < 100; j++) v[i][j] = M;
    for (int t = 0; t < N; t++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int i = x1 - 1; i < x2; i++) {
            for (int j = y1 - 1; j < y2; j++) v[i][j]--;
        }
    }
    for (int i = 0; i < 100; i++)
        for (int j = 0; j < 100; j++)
            if (v[i][j] < 0) cnt++;
    cout << cnt;
}