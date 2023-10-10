#include <bits/stdc++.h>
using namespace std;
int gcd(int n, int m);

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);
    int n, m, g, l;
    cin >> n >> m;
    g = gcd(n, m); // 최대공약수.
    n /= g;
    m /= g;
    l = n * m * g;
    cout << g << '\n' << l;
}

int gcd(int n, int m) { // 유클리드 호제법.
    if (n < m)
        swap(n, m);

    if (m == 0)
        return n;
    else
        return gcd(m, n % m);
}