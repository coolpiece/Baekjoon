#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m = -1, cnt = 0, out;
    cin >> n;
    vector<int> v(n + 1);
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        v[tmp]++;
    }
    for (int i = 1; i <= n; i++) m = max(m, v[i]);
    for (int i = 1; i <= n; i++) {
        if (m == v[i]) {
            cnt++;
            out = i;
        }
    }
    if (cnt == 1)
        cout << out;
    else
        cout << "skipped";
}