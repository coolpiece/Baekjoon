#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, num = 0, cnt = 0;
    cin >> n;
    vector<string> v;
    vector<vector<string>> couple;
    for (int i = 0; i < n; i++) {
        string p, s;
        cin >> p >> s;
        auto idx = find(v.begin(), v.end(), s);
        if (idx == v.end()) {  // 없으면 커플링 목록에 삽입.
            if (s == "-") continue;
            v.push_back(s);
            couple.push_back(vector<string>());
            couple[num++].push_back(p);
        } else
            couple[idx - v.begin()].push_back(p);
    }

    for (int i = 0; i < v.size(); i++) {
        if (couple[i].size() == 2) cnt++;
    }
    cout << cnt << '\n';

    for (int i = 0; i < v.size(); i++) {
        if (couple[i].size() == 2) cout << couple[i][0] << " " << couple[i][1] << '\n';
    }
}