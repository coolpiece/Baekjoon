#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string x, y, rst;
    int s;
    cin >> x >> y;
    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());
    s = stoi(x) + stoi(y);
    rst = to_string(s);
    reverse(rst.begin(), rst.end());
    for (int i = 0; i < rst.size(); i++) {
        if (rst[i] == '0')
            continue;
        else {
            rst = rst.substr(i, -1);
            break;
        }
    }
    cout << rst;
}