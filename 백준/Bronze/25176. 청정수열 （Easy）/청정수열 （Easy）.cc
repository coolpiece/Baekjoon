#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, rst = 1;
    cin >> n;
    for (int i = 2; i <= n; i++) rst *= i;
    cout << rst;
}