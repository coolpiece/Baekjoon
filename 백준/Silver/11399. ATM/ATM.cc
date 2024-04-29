#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, time = 0;
    cin >> n;
    vector<int> v;
    for (int i = 0; i<n; i++) {
        int p;
        cin >> p;
        v.push_back(p);
    }
    sort(v.begin(), v.end());
    for (int i = 1; i < n; i++) {  // 크기 순으로 정렬 후, 누적합 저장.
        v[i] += v[i - 1];
    }
    for (int i = 0; i < n; i++) {
        time += v[i];
    }
    cout << time;
}