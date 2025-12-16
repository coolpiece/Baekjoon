#include <bits/stdc++.h>
using namespace std;

int main(void) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int k;
    cin >> k;
    for (int T = 0; T < k; T++) {
        int p, m, over = 0;
        cin >> p >> m;
        vector<int> v(m + 1);
        for (int i = 0; i < p; i++) {
            int seat;
            cin >> seat;
            v[seat]++;
            if (v[seat] > 1) over++;
        }
        cout << over << '\n';
        ;
    }
}