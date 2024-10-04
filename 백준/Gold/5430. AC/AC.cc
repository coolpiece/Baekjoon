#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int k = 0; k < t; k++) {
        string p;
        int n, err = 0, direct = 0;  // direct이 0이면 앞부터, 1이면 뒤부터.
        char c;
        cin >> p >> n;
        deque<int> dq;
        for (int i = 0; i < n; i++) {  // 입력 받기.
            int tmp;
            cin >> c >> tmp;
            dq.push_back(tmp);
        }
        if (n == 0) cin >> c;
        cin >> c;

        for (int i = 0; i < p.length(); i++) {
            if (p[i] == 'R') {  // R 함수.
                if (direct)
                    direct = 0;
                else
                    direct = 1;
            } else {  // D 함수.
                if (dq.empty()) {
                    cout << "error\n";
                    err = 1;
                    break;
                }
                if (direct)
                    dq.pop_back();
                else
                    dq.pop_front();
            }
        }
        if (err)
            continue;
        else {
            cout << "[";
            if (dq.size()) {
                if (direct) {
                    for (int i = dq.size() - 1; i > 0; i--) cout << dq[i] << ",";
                    cout << dq[0] << "]\n";
                }
                else {
                    for (int i = 0; i < dq.size() - 1; i++) cout << dq[i] << ",";
                cout << dq[dq.size() - 1] << "]\n";
                }
            } else
                cout << "]\n";
        }
    }
}