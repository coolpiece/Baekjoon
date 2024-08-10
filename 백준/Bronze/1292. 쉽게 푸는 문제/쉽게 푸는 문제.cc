#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, cnt = 1;
    vector<int> v(1001);
    cin >> a >> b;
    for (int i = 1; ; i++) {
        for (int j = 0; j < i; j++) {
            v[cnt] = v[cnt - 1] + i;
            if (cnt == 1000) break;
            cnt++;
        }
        if (cnt == 1000) break;
    }
    cout << v[b] -v[a - 1];
}