#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        int a;
        cin >> a;
        sum += a;
    }
    cout << sum;
}