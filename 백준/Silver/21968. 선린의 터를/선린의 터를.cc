#include <bits/stdc++.h>
using namespace std;

int main(void) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    vector<long long> three(100);
    three[0] = 1;
    for (long long i = 1; i <= 100; i++) three[i] = three[i - 1] * 3;

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        long long n, idx = 0, rst = 0;
        cin >> n;
        while (n) {
            if (n % 2) rst += three[idx];
            n /= 2;
            idx++;
        }
        cout << rst << '\n';
    }
}