#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    cin >> str;
    double grade = 0, cnt = 0;
    for (int i = 0; i < str.size(); i++) {
        char c = str[i];
        cnt++;
        switch (c) {
            case 'A':
                grade += 4;
                break;
            case 'B':
                grade += 3;
                break;
            case 'C':
                grade += 2;
                break;
            case 'D':
                grade += 1;
                break;
            default:
                break;
        }

        if (i < str.size() - 1 && str[i + 1] == '+') {
            grade += 0.5;
            i++;
        }
    }
    cout << grade / cnt;
}