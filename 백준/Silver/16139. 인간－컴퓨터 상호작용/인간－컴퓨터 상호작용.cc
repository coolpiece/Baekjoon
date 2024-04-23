#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    int q;
    cin >> str >> q;

    int length = str.size();
    vector<vector<int>> v(length + 1, vector<int>(26));
    for (int i = 1; i <= length; i++) { // 누적합 계산.
        int idx = str[i - 1] - 'a';    // 벡터에 알파벳이 나타난 횟수 저장.
        for (int j = 0; j < 26; j++) {
            v[i][j] = v[i - 1][j];
        }
        v[i][idx]++;
    }
    for (int i = 0; i < q; i++) {
        char a;
        int l, r;
        cin >> a >> l >> r;
        int idx = a - 'a';
        cout << v[r + 1][idx] - v[l][idx] << '\n';
    }
}