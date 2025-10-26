#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> v(101);
    for (int i = 1; i <= 100; i++) v[i] += v[i - 1] + i * i;
    int n;
    while (1) {
        cin >> n;
        if (n == 0) return 0;
        cout << v[n] << '\n';
    }
}