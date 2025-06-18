#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n;
    vector<int> v(n);
    int mem = n, cur = 2;  // mem: 회원 수, cur: 정렬하는 그룹 수
    for (int i = 0; i < n; i++) cin >> v[i];
    cin >> k;

    while (1) {
        for (int i = 0; i <= n - cur; i += cur) {
            sort(v.begin() + i, v.begin() + i + cur);
        }
        mem /= 2;
        if (mem == k) break;
        cur *= 2;
    }

    for (int i = 0; i < n; i++) cout << v[i] << " ";
}