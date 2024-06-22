#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int c;
    string str;
    cin >> c >> str;

    vector<string> v;
    int len = str.length();

    if (c == 1) {
        cout << str << '\n'; // camel
        for (int i = 0; i < len; i++) { // snake
            if(str[i]>='A' && str[i]<='Z') {
                cout << "_" << (char)(str[i] + 'a' - 'A');
            } else
                cout << str[i];
        }
        cout << '\n';
        str[0] += 'A' - 'a'; // pascal
        cout << str;
    }

    if (c == 2) {
        for (int i = 0; i < len; i++) { // camel
            if (str[i] == '_') {
                cout << (char)(str[++i] + 'A' - 'a');
            }
            else
                cout << str[i];
        }
        cout << '\n' << str << '\n';  // snake
        cout << (char)(str[0] + 'A' - 'a');  // pascal
        for (int i = 1; i < len; i++) {
            if (str[i] == '_') {
                cout << (char)(str[++i] + 'A' - 'a');
            } else
                cout << str[i];
        }
    }

    if(c == 3) {
        cout << (char)(str[0] + 'a' - 'A');  // camel
        for (int i = 1; i < len; i++) cout << str[i];
        cout << '\n';

        cout << (char)(str[0] + 'a' - 'A');  // snake
        for (int i = 1; i < len; i++) {
            if (str[i] >= 'A' && str[i] <= 'Z') {
                cout << "_" << (char)(str[i] + 'a' - 'A');
            } else
                cout << str[i];
        }
        cout << '\n';

        cout << str; // pascal
    }
}