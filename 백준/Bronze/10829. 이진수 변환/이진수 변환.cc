#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    cin >> n;
    string str="";
    while (1) {
        if (n == 0) break;
        if (n % 2) {
            str += "1";
            n--;
            n /= 2;
        } else {
            str += "0";
            n /= 2;
        }
    }
    if (str[str.size() - 1] == '0') str.pop_back();
    reverse(str.begin(), str.end());
    cout << str;
}