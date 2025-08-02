#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b) {
    if (a < b) swap(a, b);
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, b, xsum = 0, ysum = 0, g;
    cin >> n >> b;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        xsum += x;
        ysum += y;
    }
    if (!xsum) {  // a*0 형태라 a 값이 무수히 많은 경우.
        cout << "EZPZ";
        return 0;
    }
    ysum -= n * b;
    g = gcd(abs(ysum), abs(xsum));  // 두 수의 최대공약수 구하기.
    ysum /= g;
    xsum /= g;
    if (xsum < 0) {  // 분모가 음수인 경우, 분자와 분모의 부호 변경.
        ysum = -ysum;
        xsum = -xsum;
    }

    if (xsum == 1)  // 분모가 1이면 생략.
        cout << ysum;
    else
        cout << ysum << '/' << xsum;
}