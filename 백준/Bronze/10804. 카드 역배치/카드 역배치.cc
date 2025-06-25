#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> v(21);
    for (int i = 0; i < 21; i++) v[i] = i;

    for (int i = 0; i < 10; i++) {
        int a, b;
        cin >> a >> b;
        reverse(v.begin() + a, v.begin() + b + 1);
    }
    for (int i = 1; i < 21; i++) cout << v[i] << ' ';
    return 0;
}