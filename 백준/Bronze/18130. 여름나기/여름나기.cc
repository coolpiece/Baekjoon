#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    multimap<long long, long long> m;

    for (int i = 0; i < n; i++) {
        long long p, k, c, price;
        cin >> p >> k >> c;
        k = (q - 1) / k;
        price = p + c * k * (k + 1) / 2;
        m.insert({price, i + 1});
    }
    cout << m.begin()->second << " " << m.begin()->first;
}