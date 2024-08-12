#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    int dp[101];
    bool visited[101];
    fill(&dp[0], &dp[101], 0);
    fill(&visited[0], &visited[101], false);

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        dp[x] = y;
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        dp[u] = v;
    }

    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int cur = q.front(), cube = 0;
        visited[cur] = true;
        q.pop();
        for (int i = 1; i <= 6; i++) {
            if (cur + i > 100) continue;
            if (!visited[cur + i]) {
                if (dp[cur + i]) { // 뱀이나 사다리인 경우.
                    int sl = dp[cur + i];  // 목적지 좌표.
                    dp[cur + i] = dp[cur] + 1;
                    visited[cur + i] = true;
                    if(!visited[sl]) {
                    dp[sl] = dp[cur + i];  // 이동.
                    visited[sl] = true;
                    q.push(sl);
                    }
                    if (sl == 100) break;
                } else {  // 주사위로 이동하는 경우. 최대 숫자로 이동.
                    cube = i;
                }
            }
        }
        if (cube) {
            dp[cur + cube] = dp[cur] + 1;
            visited[cur + cube] = true;
            q.push(cur + cube);
            if (cur + cube == 100) break;
        }
    }
    cout << dp[100];
}