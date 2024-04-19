#include <bits/stdc++.h>
using namespace std;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    vector<int> v, b;
    int n, d, bi = 5;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    if(n >= 2) {
        d = v[1] - v[0];
        for (int i = 1; i < n - 1; i++) {
            if(d != v[i + 1] - v[i]) {
                cout << "NO";
                return 0;
            }
        }
        cout << "YES" << '\n';
        for (int i = 0; i < n; i++) {
            cout << bi << " ";
            b.push_back(bi);
            bi += d;
        }
        cout << '\n';
        for (int i = 0; i < n; i++) {
            cout << v[i] - b[i] << " ";
        }
    }
    else {
        int x = 5;
        cout << "YES" << '\n';
        cout << x << '\n';
        cout << v[0] - x;
    }
}
