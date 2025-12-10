#include <bits/stdc++.h>
using namespace std;

int main(void) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, m = 1;
    cin >> n;
    vector<int> v(n);
    vector<int> up(n, 1);
    vector<int> down(n, 1);
    for (int i = 0; i < n; i++) cin >> v[i];
    for (int i = 1; i < n; i++)
        if (v[i] >= v[i - 1]) up[i] = up[i - 1] + 1;
    for (int i = 1; i < n; i++)
        if (v[i] <= v[i - 1]) down[i] = down[i - 1] + 1;
    for (int i = 0; i < n; i++) {
        m = max(m, up[i]);
        m = max(m, down[i]);
    }
    cout << m;
}