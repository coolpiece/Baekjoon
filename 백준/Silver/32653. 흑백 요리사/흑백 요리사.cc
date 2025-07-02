#include <bits/stdc++.h>
using namespace std;

int gcd(int n, int m) {
    if (n < m) swap(n, m);
    if (m == 0) return n;
    else
        return gcd(m, n % m);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
        int g = v[0];
        long long l = v[0];
        for (int i = 1; i < n; i++) {
        g = gcd(l, v[i]); // 최대공약수
        l *= v[i]; // 두 수의 곱
        l /= g; // 최소공배수
    }

    int mul = 1; // 최소공배수에 곱해줄 수.
    if (l % 2) mul++;  // 최소공배수의 배수 중 짝수여야함.
    int flag = 0;
    while(1) {
        for (int i = 0; i < n; i++) {
            int tmp = l * mul / v[i];
            //cout << "!"<< tmp << "\n";
            if((l*mul/v[i]) % 2) { // even 하지 않으면
                mul++; // 다음 배수 확인
                break;
            }
            if (i == n - 1) flag = 1;
        }
        if (flag) break;
    }

    cout << l * mul;
}