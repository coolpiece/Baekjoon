#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, a, b, m, output = -1, find = 0;
    cin >> n >> a >> b >> m;
    vector<vector<int>> v(n + 1, vector<int>(n + 1));
    for (int i = 0; i < m; i++) {  // 2차원 벡터에 부모-자식 관계 저장.
        int x, y;
        cin >> x >> y;
        v[x][y] = 1, v[y][x] = 1; // 인접 행렬 방식.
    }

    stack<int> s; // dfs.
    vector<bool> visited(n + 1);
    s.push(a); // 찾는 값부터 시작.
    visited[a] = true;
    while (!s.empty()) {
        int cur = s.top();
        for (int i = 1; i < n+1; i++) {
            if (v[cur][i] == 1 && !visited[i]) {
                if (i == b) { // 찾은 경우.
                    output = s.size();
                    find = 1; // 찾음 플래그.
                    break;
                }
                s.push(i);
                visited[i] = true;
                break;
            } else if (i == n) s.pop(); // 탐색을 마친 노드는 pop.
        }
        if (find) break;
    }
    cout << output;
}