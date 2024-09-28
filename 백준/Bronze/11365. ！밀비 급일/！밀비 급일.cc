#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (1) {
        string str;
        getline(cin, str);
        if (!str.compare("END"))
            break;
        else {
            reverse(str.begin(), str.end());
            cout << str << '\n';
        }
    }
}