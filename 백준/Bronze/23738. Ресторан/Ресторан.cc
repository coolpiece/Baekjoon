#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    cin >> str;
    for (int i = 0; i < str.size(); i++) {
        switch (str[i]) {
            case 'B':
                cout << "v";
                break;
            case 'E':
                cout << "ye";
                break;
            case 'H':
                cout << "n";
                break;
            case 'P':
                cout << 'r';
                break;
            case 'C':
                cout << "s";
                break;
            case 'Y':
                cout << "u";
                break;
            case 'X':
                cout << "h";
                break;
            default:
                cout << (char)(str[i] - 'A' + 'a');
                break;
        }
    }
}