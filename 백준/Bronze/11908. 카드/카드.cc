#include <bits/stdc++.h>
using namespace std;
int main(void) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n, s = 0;
    cin >> n;
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    sort(c.begin(), c.end());
    for (int i = 0; i < n - 1; i++) s += c[i];
    cout << s;
}