#include <bits/stdc++.h>
using namespace std;

int main(void) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, k, m;
    cin >> n >> k >> m;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
    }
    vector<int> v(n);
    v[k - 1] = 1;
    for (int i = 0; i < m; i++) {
        int tmp;
        cin >> tmp;
        if (tmp > 0 && k <= tmp)
            k = 1 + tmp - k;
        else if (tmp < 0 && k > n + tmp)
            k = n + tmp + n - k + 1;
    }
    cout << k;
}