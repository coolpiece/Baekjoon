#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    deque<pair<int, int>> dq;
    int n, move;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        dq.push_back({i + 1, tmp});
    }
    cout << dq.front().first<<" ";
    move = dq.front().second;
    dq.pop_front();
    for (int i = 0; i < n-1; i++) {
        if (move > 0) {  // 오른쪽.
            for (int j = 0; j < move-1; j++) {
                int idx = dq.front().first, tmp = dq.front().second;
                dq.push_back({idx, tmp});
                dq.pop_front();
            }
            cout << dq.front().first << " ";
            move = dq.front().second;
            dq.pop_front();
        }
        else {
            for (int j = 0; j < -move - 1; j++) {
                int idx = dq.back().first, tmp=dq.back().second;
                dq.push_front({idx, tmp});
                dq.pop_back();
            }
            cout << dq.back().first << " ";
            move = dq.back().second;
            dq.pop_back();
        }
    }
}