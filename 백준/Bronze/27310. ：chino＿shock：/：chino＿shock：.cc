#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    cin >> str;
    int colon = 0, underbar = 0, len = str.length();
    for (int i = 0; i < len; i++) {
        if (str[i] == ':')
        colon++;
        else if (str[i] == '_')
            underbar++;
    }
    cout << len + colon + underbar * 5;
}