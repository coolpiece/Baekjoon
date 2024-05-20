#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, d, count = 0, max = -1;
    cin >> n >> d;
    vector<int> v(300001);
    for (int i = 0; i < n; i++) {  // 각 높이의 건물이 몇 개인지 저장.
        int h;
        cin >> h;
        v[h]++;
        if (h > max) max = h;
    }

    for (int i = 0; i < d; i++) {
        if(max > 0) {
            v[max - 1] += v[max];
            count += v[max];
            v[max] = 0;
            max--;
        }
    }
    cout << count;
}