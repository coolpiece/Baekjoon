#include <bits/stdc++.h>
using namespace std;
int r, c, cnt = 0;

void div(int x, int y, int n) {
    if (n > 2) {
        if (r < x + n / 2) {
            if (c < y + n / 2)
                div(x, y, n / 2);
            else {
                cnt += pow(n / 2, 2);
                div(x, y + n / 2, n / 2);
            }
        } else {
            if (c < y + n / 2) {
                cnt += pow(n / 2, 2) * 2;
                div(x + n / 2, y, n / 2);
            } else {
                cnt += pow(n / 2, 2) * 3;
                div(x + n / 2, y + n / 2, n / 2);
            }
        }
    } else {  // n이 2면 z모양으로 탐색.
        if (r == x && c == y)
            cout << cnt;
        else if (r == x && c == y + 1)
            cout << cnt + 1;
        else if (r == x + 1 && c == y)
            cout << cnt + 2;
        else if (r == x + 1 && c == y + 1)
            cout << cnt + 3;
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n >> r >> c;
    n = pow(2, n);

    if (r < n / 2) {
        if (c < n / 2)
            div(0, 0, n / 2);
        else {
            cnt += pow(n / 2, 2);
            div(0, n / 2, n / 2);
        }
    } else {
        if (c < n / 2) {
            cnt += pow(n / 2, 2) * 2;
            div(n / 2, 0, n / 2);
        } else {
            cnt += pow(n / 2, 2) * 3;
            div(n / 2, n / 2, n / 2);
        }
    }
}