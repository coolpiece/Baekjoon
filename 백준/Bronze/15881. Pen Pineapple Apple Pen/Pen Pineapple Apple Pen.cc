#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, cnt = 0;
    string str;
    cin >> n >> str;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == 'p' && i + 3 < str.length()) {
            if (str[i + 1] == 'P' && str[i + 2] == 'A' && str[i + 3] == 'p') {
                cnt++;
                i += 3;
            }
        }
    }
    cout << cnt;
}