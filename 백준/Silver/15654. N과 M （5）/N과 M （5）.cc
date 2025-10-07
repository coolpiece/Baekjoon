#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> visited(9);
vector<int> num;
vector<int> arr(9);

void dfs(int dep) {
    if (dep == m) {
        for (int i = 0; i < m; i++) cout << arr[i] << ' ';
        cout << '\n';
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            visited[i] = 1;
            arr[dep] = num[i];
            dfs(dep + 1);
            visited[i] = 0;
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        num.push_back(tmp);
    }
    sort(num.begin(), num.end());
    dfs(0);
}