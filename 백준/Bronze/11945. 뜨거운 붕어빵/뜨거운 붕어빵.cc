#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<string> v(n);

    for (int i = 0; i < n; i++) {
        if(m) cin >> v[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = m - 1; j >= 0; j--) {
            cout << v[i][j];
        }
        cout << '\n';
    }
}