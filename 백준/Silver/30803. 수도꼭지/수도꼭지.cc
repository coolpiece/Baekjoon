#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    long long rst1 = 0;
    cin >> n;
    vector<int> v(n + 1);
    vector<int> toggle(n + 1);
    for (int i = 1; i < n + 1; i++) {
        cin >> v[i];
        rst1 += v[i];
        toggle[i] = 1;
    }
    cin >> q;
    cout << rst1 << '\n';

    long long rst2 = rst1;

    for (int j = 0; j < q; j++) {
        int tog, i;
        cin >> tog >> i;
        if (tog == 1) {
            int x;
            cin >> x;
            rst2 -= v[i] * toggle[i];
            rst2 += x * toggle[i];
            v[i] = x;
        } else {
            rst2 -= v[i] * toggle[i];
            toggle[i] = !toggle[i];
            rst2 += v[i] * toggle[i];
        }

        cout << rst2 << '\n';
    }
}