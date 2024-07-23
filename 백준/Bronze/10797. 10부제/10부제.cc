#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, cnt = 0;
    cin >> n;
    for (int i = 0; i < 5; i++) {
        int tmp;
        cin >> tmp;
        if (tmp % 10 == n) cnt++;
    }
    cout << cnt;
}