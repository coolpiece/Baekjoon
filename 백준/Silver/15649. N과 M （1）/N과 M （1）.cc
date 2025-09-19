#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> visited(9);
vector<int> arr(9);

void dfs(int dep) {
    if (dep == m) {  // 길이를 다 채웠으면 배열 출력.
        for (int i = 0; i < m; i++) cout << arr[i] << ' ';
        cout << '\n';
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            visited[i] = 1; // 방문 표시.
            arr[dep] = i; // 배열의 dep번째에 i 삽입.
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