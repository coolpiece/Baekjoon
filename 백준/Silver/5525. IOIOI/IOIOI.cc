#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, cnt = 0;
    string p = "IOI", s;
    cin >> n >> m >> s;
    for (int i = 1; i < n; i++) p.append("OI");
    while(!s.empty()) {
        string::size_type idx;
        idx = s.find(p);
        if (string::npos == idx) break;
        else {
            cnt++;
            s = s.substr(idx + 1);
        }
    }
    cout << cnt;
}