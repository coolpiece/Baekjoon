#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    deque<int> dq;
    for (int i = n; i > 0; i--) {
        dq.push_front(i);
        for (int j = 0; j < i; j++) {  // i번 반복.
            int tmp = dq.back();
            dq.push_front(tmp);
            dq.pop_back();
        }
    }
    for (int j = 0; j < dq.size(); j++) cout << dq[j] << " ";
}