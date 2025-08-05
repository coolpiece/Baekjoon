#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, r = 1;
    string str;
    cin >> n >> str;

    vector<int> v(21);
    v[0] = 1;
    v[1] = 1;
    for (int i = 2; i < 21; i++) v[i] = v[i - 2] + v[i - 1];

    for (int i = 0; i < n; i++) {
        int l = 0;
        while (i + 3 < n && str.substr(i, 4) == "long") {
            l++;
            i += 4;
        }
        if (l >= 2) r *= v[l];
    }
    cout << r;
}