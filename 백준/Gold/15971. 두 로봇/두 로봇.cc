#include <bits/stdc++.h>
#define MAX 999999999
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, b, e;
    cin >> n >> b >> e;
    vector<vector<int>> v(n + 1, vector<int>(n + 1));
    vector<int> dis(n + 1);
    vector<int> maxpass(n + 1);

    for (int i = 0; i < n - 1; i++) {
        int p, q, l;
        cin >> p >> q >> l;
        v[p][q] = l;
        v[q][p] = l;
    }
    for (int i = 1; i <= n; i++) dis[i] = MAX;

    stack<int> s;
    s.push(b);
    dis[b] = 0;
    maxpass[b] = 0;
    while (!s.empty()) {
        int cur = s.top();
        for (int i = 1; i <= n; i++) {
            if (v[cur][i] > 0) {
                if (dis[i] == MAX || dis[i] > dis[cur] + v[cur][i]) {
                    s.push(i);
                    dis[i] = dis[cur] + v[cur][i];
                    maxpass[i] = max(maxpass[cur], v[cur][i]);
                    break;
                }
            }
            if (i == n) s.pop();  // 더 이상 나아갈 곳이 없는 경우.
        }
    }
    cout << dis[e] - maxpass[e];
}