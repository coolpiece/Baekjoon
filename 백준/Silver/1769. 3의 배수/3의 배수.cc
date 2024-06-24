#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    cin >> str;

    int cnt = 0, len = str.length();
    while(len >= 2) {
        cnt++;
        int sum = 0;
        len = str.length();
        for (int i = 0; i < len; i++) {
            sum += str[i] - '0';
        }
        str.clear();
        str += to_string(sum);
        if (sum < 10) break;
    }
    if (stoi(str) == 3 || stoi(str) == 6 || stoi(str) == 9) {
        cout << cnt << "\nYES";
    }
    else
        cout << cnt << "\nNO";
}