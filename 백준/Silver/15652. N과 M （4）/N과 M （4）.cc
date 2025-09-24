#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> rst(9);

void dfs(int dep) {
    if (dep == m) {
        for (int i = 0; i < m; i++) cout << rst[i] << ' ';
        cout << '\n';
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (dep == 0) rst[dep] = i; // 배열의 맨 앞에 들어가는 경우.
        else if(rst[dep - 1] <= i) rst[dep] = i;
        else
            continue;
        dfs(dep + 1);
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    dfs(0);
}