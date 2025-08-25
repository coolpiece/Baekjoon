#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        string str;
        cin >> str;
        int pos = 0, flag = 1, len = str.size();
        if (str[pos] < 'A' || str[pos] > 'F')
            flag = 0;
        else if (str[pos] != 'A')
            pos++;
        if (str[pos] != 'A') flag = 0;
        while (flag && str[pos] == 'A' && pos < len - 2) pos++;
        if (str[pos] != 'F') flag = 0;
        while (flag && str[pos] == 'F' && pos < len - 1) pos++;
        if (str[pos] != 'C') flag = 0;
        while (flag && str[pos] == 'C' && pos < len) pos++;
        if (str[len - 1] < 'A' || str[len - 1] > 'F') flag = 0;

        if (flag)
            cout << "Infected!\n";
        else
            cout << "Good\n";
    }
}