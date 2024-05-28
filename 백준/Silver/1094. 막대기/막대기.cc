#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x, cur = 64, count = 1;
    cin >> x;
    while(1) {
        if (cur == x) break;
        if (cur / 2 >= x) {
            cur /= 2;
        }
        else { // 절반이 더 작으면 더 자른 후 더하기.
            if (cur != 1) cur /= 2;
            x -= cur;
            count++;
        }
    }
    cout << count;
}