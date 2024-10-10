/*
30804
*/
#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, ty, cnt = 1;
    cin >> n >> ty;
    vector<pair<int, int>> v;  // {과일 종류, 개수}
    if (n == 1) v.push_back({ty, cnt});
    for (int i = 1; i < n; i++) {  // 입력.
        int tmp;
        cin >> tmp;
        if (ty == tmp)
            cnt++;  // 같은 종류.
        else {      // 새로운 종류.
            v.push_back({ty, cnt});
            ty = tmp;
            cnt = 1;
        }
        if (i == n - 1) v.push_back({ty, cnt});
    }

    int m = v[0].second;
    if (v.size() >= 2) m += v[1].second;
    for (int i = 1; i < v.size(); i++) {
        int a = v[i - 1].first, b = v[i].first, pcs = v[i - 1].second + v[i].second;
        for (int j = i + 1; j < v.size(); j++) {
            if (v[j].first == a || v[j].first == b) {
                pcs += v[j].second;
                i++;
            }
            else
                break;
        }
        // cout << i - 1 << ", " << i << " : " << pcs << '\n';
        m = max(m, pcs);
    }
    cout << m;
}