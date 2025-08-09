#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    map<string, int> s;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < str.length(); j++) {
            if (str[j] == '.') str = str.substr(j + 1, str.length());
        }
        s[str]++;
    }

    for (auto i = s.begin(); i != s.end(); i++) cout << i->first << ' ' << i->second << '\n';
}