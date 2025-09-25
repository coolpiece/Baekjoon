#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int T = 0; T < t; T++) {
        int n, w1 = 0, w2 = 0;
        string s1, s2;
        cin >> n >> s1 >> s2;
        for (int i = 0; i < n; i++) {
            if (s1[i] == 'W') w1++;
            if (s2[i] == 'W') w2++;
        }

        int flip = abs(w1 - w2), cnt = 0;
        // 색깔별 말의 개수가 일치하면 자리만 바꾸면 됨. 일치하지 않으면 뒤집어야 함.
        // flip: 뒤집어야 하는 말의 수, cnt: 일치하지 않는 말의 수.

        for (int i = 0; i < n; i++)
            if (s1[i] != s2[i]) cnt++;

        if (flip) {  // 말의 수가 일치하지 않으면 일치하게 뒤집은 후 자리 바꿔야 함.
            cnt -= flip;
            cout << cnt / 2 + flip << '\n';
        } else  // 말의 수가 일치하면 2개씩 짝지어서 자리만 바꾸면 됨.
            cout << cnt / 2 << '\n';
    }
}