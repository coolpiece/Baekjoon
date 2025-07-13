#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str = "SciComLove";
    int n;
    cin >> n;
    n %= 10;
    string tmp = str.substr(0, n);
    str.append(tmp);
    str.erase(str.begin(), str.begin() + n);
    cout << str;
}