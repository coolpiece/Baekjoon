#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, rst = 0;
    cin >> n;
    vector<int> v(51);
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        v[tmp]++;
    }

    for (int i = 0; i < 51; i++) {
        if (v[i] == i) rst = i;
    }
    if (!rst && v[0] > 0) rst = -1;
    cout << rst;
}