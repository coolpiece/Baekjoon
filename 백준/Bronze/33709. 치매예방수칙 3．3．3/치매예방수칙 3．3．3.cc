#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, sum = 0;
    string str, tmp = "";
    cin >> n >> str;

    for (int i = 0; i < n; i++) {
        if (str[i] == '.' || str[i] == '|' || str[i] == ':' || str[i] == '#') {
            sum += stoi(tmp);
            tmp = "";
        } else
            tmp += str[i];
    }
    sum += stoi(tmp);
    cout << sum;
}