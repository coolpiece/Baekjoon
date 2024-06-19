#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int v[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
            if (v[i][j] == 0) v[i][j] = 999;  // 경로가 없다는 것을 의미
        }
    }

    for (int i = 0; i < n; i++)  // 플로이드-워셜 알고리즘
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++) v[j][k] = min(v[j][k], v[j][i] + v[i][k]);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (v[i][j] == 999)
                v[i][j] = 0;
            else
                v[i][j] = 1;
            cout << v[i][j] << " ";
        }
        cout << '\n';
    }
}