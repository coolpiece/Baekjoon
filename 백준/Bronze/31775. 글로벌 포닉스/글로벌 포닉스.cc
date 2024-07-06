#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<string> v(3);
    cin >> v[0] >> v[1] >> v[2];
    sort(v.begin(), v.end());
    if (v[0][0] == 'k' && v[1][0] == 'l' && v[2][0] == 'p') cout << "GLOBAL";
    else
        cout << "PONIX";
}