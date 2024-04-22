#include <bits/stdc++.h>
using namespace std;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    string output;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        if (output.empty()) {
            output = str;
            continue;
        }

        for (int j = 0; j < str.size(); j++) {
            if (output[j] != str[j]) output[j] = '?';
        }
    }
    cout << output;
}