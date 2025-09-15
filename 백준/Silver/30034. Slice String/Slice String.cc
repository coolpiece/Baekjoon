#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k, s;
    string str;
    cin >> n;
    set<char> ch;  // 구분자.
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        ch.insert(c);
    }
    cin >> m;
    for (int i = n; i < n + m; i++) {
        char c;
        cin >> c;
        ch.insert(c);
    }
    ch.insert(' ');
    cin >> k;
    for (int i = 0; i < k; i++) {  // 병합자.
        char c;
        cin >> c;
        ch.erase(c);  // 구분자 목록에서 제외.
    }
    cin >> s;
    cin.ignore();
    getline(cin, str);
    vector<string> v;
    string tmp = "";

    for (int i = 0; i < s; i++) {
        if (ch.find(str[i]) != ch.end()) {  // 구분자 목록에 있는 경우.
            if (!tmp.empty()) {
                cout << tmp << '\n';
                tmp = "";
            }
            continue;
        } else
            tmp += str[i];
    }
    if (!tmp.empty()) cout << tmp;
}