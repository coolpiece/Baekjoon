#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    while (cin >> str) {
        if (!str.compare("end")) break;

        int aeiou = 0, flag = 0, m = 0;
        char cur = ' ';
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') {  // 모음일 때.
                aeiou++;
                if (m <= 0)
                    m = 1;
                else
                    m++;

                if (m >= 3) {
                    flag = -1;
                    break;
                }
            } else {  // 자음일 때.
                if (m >= 0)
                    m = -1;
                else
                    m--;

                if (m <= -3) {
                    flag = -1;
                    break;
                }
            }

            if (cur == str[i] && str[i] != 'e' && str[i] != 'o') {
                flag = -1;
                break;
            }
            cur = str[i];
        }
        if (!aeiou) flag = -1;

        if (flag == -1)
            cout << "<" << str << "> is not acceptable.\n";
        else
            cout << "<" << str << "> is acceptable.\n";
    }
}