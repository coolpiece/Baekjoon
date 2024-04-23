#include <bits/stdc++.h>
using namespace std;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    string str;
    int q;
    cin >> str >> q;

    vector<vector<int>> v(str.size(), vector<int>(26));
    for (int i = 0; i < str.size(); i++) { // 누적합 계산.
        int idx = str[i] - 'a'; // 벡터에 알파벳이 나타난 횟수 저장.
        for (int j = i; j < str.size(); j++) {
            v[j][idx]++;
        }
    }
    for (int i = 0; i < q; i++) {
        char a;
        int l, r;
        cin >> a >> l >> r;
        if(!l) cout << v[r][a - 'a'] << '\n'; // l이 0인 경우.
        else cout << v[r][a - 'a'] - v[l - 1][a - 'a'] << '\n';
    }
}