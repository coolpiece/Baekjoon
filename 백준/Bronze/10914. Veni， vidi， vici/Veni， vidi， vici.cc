#include <bits/stdc++.h>
using namespace std;

int main(void) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    string str;
    while (cin >> str) {
        if (str.size() % 2) str.pop_back();
        for (int i = 0; !str.empty() && i < str.size() - 1;) {
            cout << (char)((str[i] - 'a' + str[i + 1] - 'a' - n + 26) % 26 + 'a');
            i += 2;
        }
        cout << ' ';
    }
}