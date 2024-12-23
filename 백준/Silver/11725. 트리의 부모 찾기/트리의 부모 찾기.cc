#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<vector<int>> v(n + 1);
    vector<int> parent(n + 1);

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    bool visited[n + 1];
    memset(visited, false, (n + 1) * sizeof(bool));
    queue<int> q;  // bfs.
    q.push(1);
    while (!q.empty()) {
        int i = q.front();
        q.pop();
        for (int j = 0; j < v[i].size(); j++) {  // 자식 읽기.
            int cur = v[i][j];
            if (!visited[cur]) {
                visited[cur] = true;
                parent[cur] = i;  // 부모 노드 번호.
                q.push(cur);      // 발견하지 못하면 다음 노드 읽기.
            }
        }
    }

    for (int i = 2; i < n + 1; i++) {
        cout << parent[i] << '\n';
    }
}