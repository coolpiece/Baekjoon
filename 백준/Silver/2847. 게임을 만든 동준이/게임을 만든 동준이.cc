#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, cnt = 0;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    reverse(v.begin(), v.end());
    for (int i = 1; i < n; i++) {
        if (v[i] >= v[i - 1]) {
            cnt += v[i] - v[i - 1] + 1;
            v[i] = v[i - 1] - 1;
        }
    }
    cout << cnt;
}