#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    if (m <= 2)
        cout << "NEWBIE!";
    else if (m <= n)
        cout << "OLDBIE!";
    else
        cout << "TLE!";
}