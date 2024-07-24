#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    int connect[n][n];
    fill(connect[0], connect[n], 999);
    for (int i = 0; i < n; i++) connect[i][i] = 0;

    for (int i = 0; i < m; i++) {  // 연결정보 저장.
        int a, b;
        cin >> a >> b;
        connect[a - 1][b - 1] = 1;
        connect[b - 1][a - 1] = 1;
    }

    for (int i = 0; i < n; i++) {  // 플로이드-워셜 알고리즘
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                connect[j][k] = min(connect[j][k], connect[j][i] + connect[i][k]);
                connect[k][j] = connect[j][k];
            }
        }
    }

    vector<int> v, vv;
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++)
            cnt += connect[i][j];
            v.push_back(cnt);
    }
    vv = v;
    sort(v.begin(), v.end());
    int idx = find(vv.begin(), vv.end(), v[0]) - vv.begin();
    cout << idx+1;
}