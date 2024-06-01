#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        int len = str.length();
        for (int j = 0; j < len; j++) {
            if (str[j] >= 'A' && str[j] <= 'Z') {
                str[j] = str[j] - 'A' + 'a';
            }
        }
        cout << str << '\n';
    }
}