#include <bits/stdc++.h>
using namespace std;

vector<int> graph[100001];
vector<int> visited(100001);
int n, m, r, order = 1;

void dfs(vector<int> graph[], vector<int>& visited, int cur) {
    visited[cur] = order++;
    for (int i : graph[cur]) {
        if (!visited[i]) {
            dfs(graph, visited, i);
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> r;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for (int i = 0; i < n; i++) {
        sort(graph[i].begin(), graph[i].end());
    }
    dfs(graph, visited, r);
    for (int i = 1; i < n + 1; i++) cout << visited[i] << '\n';
}