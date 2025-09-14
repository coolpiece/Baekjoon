#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v[i] = a - b;
        if (i) v[i] += v[i - 1];
    }

    for (int i = 0; i < n; i++) cout << v[i] << '\n';
}