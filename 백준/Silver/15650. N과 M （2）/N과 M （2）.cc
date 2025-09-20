#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> visited(9);
vector<int> arr(9);

void dfs(int dep) {
    if (dep == m) {
        for (int i = 0; i < m; i++) cout << arr[i] << " ";
        cout << '\n';
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (!visited[i] && (!dep || (dep && i > arr[dep - 1]))) {
            visited[i] = 1;
            arr[dep] = i;
            dfs(dep + 1);
            visited[i] = 0;
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    dfs(0);
}