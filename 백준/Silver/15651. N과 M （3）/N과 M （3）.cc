#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> visited(8);
vector<int> arr(8);

void dfs(int dep) {
    if (dep == m) {
        for (int i = 0; i < m; i++) cout << arr[i] << " ";
        cout << '\n';
        return;
    }
    for (int i = 1; i <= n; i++) {
        visited[i] = 1;
        arr[dep] = i;
        dfs(dep + 1);
        visited[i] = 0;
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    dfs(0);
}