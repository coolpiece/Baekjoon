#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, cnt = 0;
    cin >> n >> m;
    deque<int> dq;
    vector<int> v(m);
    for (int i = 0; i < n; i++) dq.push_back(i + 1);
    for (int i = 0; i < m; i++) cin >> v[i];
    for (int i = 0; i < m; i++) {
        if (v[i] == dq.front())
            dq.pop_front();
        else {  // 앞, 뒤 중 가까운 쪽으로 이동.
            int idx;
            for (int j = 0; j < dq.size(); j++) {
                if (v[i] == dq[j]) idx = j;  // 원소의 현 위치 찾기.
            }
            if (dq.size() / 2 >= idx) {  // 왼쪽으로 이동.
                cnt += idx;
                for (int j = 0; j < idx; j++) {
                    int tmp = dq.front();
                    dq.push_back(tmp);
                    dq.pop_front();
                }
                dq.pop_front();
            } else {  // 오른쪽으로 이동.
                cnt += dq.size() - idx;
                for (int j = 0; j < dq.size() - idx; j++) {
                    int tmp = dq.back();
                    dq.push_front(tmp);
                    dq.pop_back();
                }
                dq.pop_front();
            }
        }
    }
    cout << cnt;
}