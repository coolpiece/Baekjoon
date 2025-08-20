#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long a, b, cnt;
    cin >> a >> b;
    cnt = 2 * llabs(b - a) / llabs((long double)b);
    cout << cnt;
}