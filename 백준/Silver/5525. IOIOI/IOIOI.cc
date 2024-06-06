#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, cnt = 0;
    string s;
    cin >> n >> m >> s;

    vector<int> v;
    for (int i = 0; i < m; i++) {
        int len = 1;
        string::size_type idx;

        idx = s.find("IOI", i);
        if (string::npos == idx)
            break;
        else
            idx += 2;

        while (idx < m - 2) {
            if (s[idx + 1] == 'O' && s[idx + 2] == 'I') {
                len++;
                idx += 2;
            } else
                break;
        }
        i = idx;
        v.push_back(len);
    }

    for (int i = 0; i < v.size(); i++) {
        if (v[i] >= n) cnt += v[i] - n + 1;
    }
    cout << cnt;
}