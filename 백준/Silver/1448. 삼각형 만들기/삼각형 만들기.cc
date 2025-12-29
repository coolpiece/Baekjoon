#include <bits/stdc++.h>
using namespace std;

int main(void) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end(), greater<>());
    for (int i = 0; i < n - 2; i++) {
        if (v[i] >= v[i + 1] + v[i + 2]) continue;
        cout << v[i] + v[i + 1] + v[i + 2];
        return 0;
    }
    cout << -1;
}