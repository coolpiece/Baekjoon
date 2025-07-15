#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, cnt = 0;
    cin >> n;
    vector<int> v(11);
    for (int i = 1; i < 11; i++) v[i] = -1;
    for (int i = 0; i < n; i++) {
        int num, pos;
        cin >> num >> pos;
        if (v[num] == -1) v[num] = pos; // 초기 위치.
        else if(v[num]!=pos) {
            cnt++;
            v[num] = pos;
        }
    }
    cout << cnt;
}