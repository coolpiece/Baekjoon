#include <bits/stdc++.h>
using namespace std;
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, k, cnt = 0;
    cin >> n >> k;
    vector<long long> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    for (int i = 0; i < n / 2; i++) {
        if (v[i] == v[n - i - 1]) {
            continue;
        } else {
            int cnt1, cnt2, plusk;
            long long a, b;
            a = v[i], b = v[n - i - 1];  // a가 더 작은 수.
            if (v[i] > v[n - i - 1]) {
                swap(a, b);
            }

            plusk = (b - a) / k;  // +K 연산 횟수.
            a += plusk * k;

            if (a == b) {
                cnt += plusk;
                continue;
            } else {  // 여전히 작으면 +1 연산 수행.
                cnt1 = plusk + b - a;
            }

            a += k;  // +K 연산 한 번 더. a > b가 됨.
            cnt2 = plusk + 1 + a - b;
            // cout << cnt1 << " " << cnt2 << '\n';
            cnt += min(cnt1, cnt2);
        }
    }
    cout << cnt;
}