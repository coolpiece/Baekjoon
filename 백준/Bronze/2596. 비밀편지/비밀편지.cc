#include <bits/stdc++.h>
using namespace std;

int main(void) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    string str, rst;
    vector<string> v = {"000000", "001111", "010011", "011100", "100110", "101001", "110101", "111010"};
    cin >> n >> str;
    for (int i = 0; i < n; i++) {
        string tok = str.substr(i * 6, 6);
        int flag = 1;
        for (int j = 0; j < 8; j++) {
            if (!v[j].compare(tok)) {
                rst += 'A' + j;
                flag = 0;
                break;
            }
        }
        if (flag) {
            for (int j = 0; j < 8; j++) {
                int dif = 0;
                for (int k = 0; k < 6; k++) {
                    if (v[j][k] != tok[k]) dif--;
                }
                if (dif == -1) {
                    rst += 'A' + j;
                    flag = 0;
                    break;
                }
            }
            if (flag) {
                cout << i + 1;
                return 0;
            }
        }
    }
    cout << rst;
}