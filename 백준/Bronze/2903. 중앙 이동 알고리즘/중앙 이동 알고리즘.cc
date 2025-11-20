#include <bits/stdc++.h>
using namespace std;

int main(void) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> v(16);
    v[0] = 2;
    for (int i = 1; i <= 15; i++) v[i] = 2 * v[i - 1] - 1;
    cout << v[n] * v[n];
}