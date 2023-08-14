#include <bits/stdc++.h>
using namespace std;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    int t, n;
    vector<int> zero(41), one(41);
    cin >> t;
    zero[0] = 1;
    one[0] = 0;
    for (int i = 1; i < 41; i++) {
        zero[i] = one[i - 1];
        one[i] = zero[i - 1] + one[i - 1];
    }
    for (int i = 0; i < t; i++) {
        cin >> n;
        cout << zero[n] << " " << one[n] << "\n";
    }
}