#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    while (cin >> n >> k) {
        int rst = n;
        while (n >= k) {
            rst += n / k;
            n = n % k + n / k;
        }
        cout << rst << '\n';
    }
}