#include <bits/stdc++.h>
using namespace std;

string s = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;\'ZXCVBNM,./";
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    while (getline(cin, str)) {
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == ' ')
                cout << ' ';
            else {
                int idx = s.find(str[i]);
                cout << s[idx - 1];
            }
        }
        cout << '\n';
    }
    return 0;
}