#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> len(n + 1);
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        int l;
        cin >> l;
        len[i] = l; // 각 탭의 길이 저장.
        v[i] = l + v[i - 1];  // 탭의 끝 위치 저장. (누적합)
    }

    int l, cur, min_move, max_move;
    int q;
    cin >> l >> q;

    for (int i = 0; i < q; i++) {
        int tap;
        cin >> tap;
        cur = 2 * v[tap - 1] + len[tap] - l;  // 위치 값.
        // max(0, min(sum(i-1) + l(i)/2 - L/2, max(0, sum(N) - L)));
        min_move = max(0, cur);
        max_move = max(0, v[n]- l);
        cur = max(0, min(cur, 2 * max_move));

        cout << fixed << setprecision(2) << (double)cur / 2.0 << '\n';
    }
}