#include <bits/stdc++.h>
using namespace std;

int n, m, r, order = 1;
vector<int> visited(100001);
vector<int> graph[100001];

void dfs(vector<int> &visited, vector<int> graph[], int r) {
    if(!visited[r]) {
        visited[r] = order++;
        for (int i = 0; i < graph[r].size(); i++) {
            if (!visited[graph[r][i]]) dfs(visited, graph, graph[r][i]);
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

    for (int i = 0; i < n + 1; i++) {
        sort(graph[i].begin(), graph[i].end(), greater<int>());
    }

    dfs(visited, graph, r);

    for (int i = 1; i < n + 1; i++) {
        cout << visited[i] << '\n';
    }
}