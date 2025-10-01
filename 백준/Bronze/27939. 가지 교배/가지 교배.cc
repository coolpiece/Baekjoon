#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        char tmp;
        cin >> tmp;
        if (tmp == 'P')
            v[i] = 0;
        else
            v[i] = 1;
    }
    cin >> m >> k;
    vector<int> sub(m);
    for (int i = 0; i < m; i++) {
        int c = 0;
        for (int j = 0; j < k; j++) {
            int num;
            cin >> num;
            c += v[num - 1];
        }
        if (c == k) sub[i] = 1; // 모두 흰색인 경우에만 흰색.
        else
            sub[i] = 0; // 아닌 경우 보라색.
    }

    int rst = 0;
    for (int i = 0; i < m; i++) rst += sub[i];
    if (!rst) cout << 'P';
    else
        cout << 'W';
}