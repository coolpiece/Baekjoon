#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, cnt = 0;
    cin >> n >> k;
    vector<int> amount(n);
    for (int i = 0; i < n; i++) {
        cin >> amount[i];
    }
    reverse(amount.begin(), amount.end());
    for (int i = 0; i < n; i++) {
        cnt += k / amount[i];
        k %= amount[i];
    }
    cout << cnt;
}