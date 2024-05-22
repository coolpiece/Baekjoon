#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string a, b;
    cin >> a >> b;

    reverse(a.begin(), a.end()); // 숫자 뒤집어서 일의 자리부터 더함.
    reverse(b.begin(), b.end());
    int al = a.length(), bl = b.length(), n;
    if (al >= bl) {
        n = al;
        for (int i = bl; i < al; i++) {
            b.append("0");
        }
    } else {
        n = bl;
        for (int i = al; i < bl; i++) {
            a.append("0");
        }
    }
    vector<int> v(n + 1);
    for (int i = 0; i < n; i++) {
        int x = a[i] - '0', y = b[i] - '0';
        v[i] += x + y;
        if (v[i] >= 10) {
            v[i] -= 10;
            v[i + 1]++;
        }
    }
    reverse(v.begin(), v.end());
    if (v[0]) cout << v[0];
    for (int i = 1; i < n + 1; i++) {
        cout << v[i];
    }
}