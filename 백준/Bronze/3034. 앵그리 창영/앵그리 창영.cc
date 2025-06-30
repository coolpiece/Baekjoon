#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, w, h, len;
    cin >> n >> w >> h;
    len = w * w + h * h;
    len = sqrt(len);
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        if (tmp <= len) cout << "DA\n";
        else
            cout << "NE\n";
    }
}