#include <bits/stdc++.h>

using namespace std;

int main()

{

    double a, b, c, d, m=0, n=0;

    cin >> a >> b >> c >>d;

    m=a/c + b/d;

    if(m < c/d + a/b) {

        m = c/d + a/b;

        n=1;

    }

    if(m < d/b + c/a) {

        m = d/b + c/a;

        n=2;

    }

    if(m < b/a + d/c) {

        m = b/a + d/c;

        n=3;

    }

    cout << n;

}