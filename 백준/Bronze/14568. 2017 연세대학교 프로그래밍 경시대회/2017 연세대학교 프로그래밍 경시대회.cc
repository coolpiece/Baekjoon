#include <bits/stdc++.h>
using namespace std;
int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, s = 0;
    cin >> n;
    if (n < 6) cout << "0";
    else {
        for(int i=1; i<=n / 2 - 2; i++) s += i;
        cout << s;
    }
}