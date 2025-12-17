#include <bits/stdc++.h>
using namespace std;

int main(void) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, m, start, end, INF = 100000000;
    cin >> n >> m;
    vector<vector<int>> v(n + 1, vector<int>(n + 1, INF));
    vector<bool> visited(n + 1);
    vector<int> dis(n + 1, INF);
    for (int i = 0; i < m; i++) {
        int s, e, cost;
        cin >> s >> e >> cost;
        v[s][e] = min(v[s][e], cost);
    }
    cin >> start >> end;
    dis[start] = 0;
    visited[start] = true;
    int cur = start;
    for (int i = 1; i <= n; i++) {
        visited[cur] = true;
        for (int j = 1; j <= n; j++)
            if (visited[j] == false) dis[j] = min(dis[j], dis[cur] + v[cur][j]);

        int min_val = INF;
        for (int j = 1; j <= n; j++) {
            if (visited[j] == false && dis[j] < min_val) {
                min_val = dis[j];
                cur = j;
            }
        }
    }
    cout << dis[end];
}