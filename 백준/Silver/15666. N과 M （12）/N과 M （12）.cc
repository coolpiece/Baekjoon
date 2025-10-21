#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> num;
vector<int> arr(9);
vector<int> cur(9);  // cur[dep]: 수열의 (dep+1)번째에 가장 최근에 들어간 수.

void dfs(int dep) {
    if (dep == m) {
        for (int i = 0; i < m; i++) cout << arr[i] << ' ';
        cout << '\n';
        return;
    }

    for (int i = 0; i < n; i++) {
        if (cur[dep] != num[i] && (!dep || (dep && arr[dep - 1] <= num[i]))) {
            cur[dep] = num[i];
            arr[dep] = num[i];
            dfs(dep + 1);
        }
    }
    cur[dep] = 0;
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