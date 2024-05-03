#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, c;
    while (cin >> a >> b >> c) {
        int count = 0;
        while (b - a != 1 || c - b != 1) {
            if (b - a > c - b) {  // 간격이 더 넓은 쪽으로 점프.
                if (b - a != 1) {
                    c = b;
                    b = b - 1;
                    count++;
                }
            } else {
                if (c - b != 1) {
                    a = b;
                    b = b + 1;
                    count++;
                }
            }
        }
        cout << count << '\n';
    }
}