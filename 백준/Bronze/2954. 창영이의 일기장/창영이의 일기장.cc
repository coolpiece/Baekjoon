#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    getline(cin, str);
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') {
            cout << str[i];
            i += 2;
        } else
            cout << str[i];
    }
}