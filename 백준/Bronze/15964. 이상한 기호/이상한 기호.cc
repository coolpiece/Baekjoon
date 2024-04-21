#include <bits/stdc++.h>
using namespace std;
long long cal(int, int);

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    int a, b;
    long long output;
    cin >> a >> b;
    output = cal(a, b);
    cout << output;
}

long long cal(int a, int b) { return pow(a, 2) - pow(b, 2); }