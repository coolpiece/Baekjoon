#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, t, p, tset = 0, pset;
    vector<int> size(6);
    cin >> n;
    for (int i = 0; i < 6; i++) {
        cin >> size[i];
    }
    cin >> t >> p;

    for (int i = 0; i < 6; i++) {
        tset += size[i] / t;
        if (size[i] % t) tset++;
    }
    cout << tset << '\n';
    pset = n / p;
    cout << pset << " " << n % p;
}