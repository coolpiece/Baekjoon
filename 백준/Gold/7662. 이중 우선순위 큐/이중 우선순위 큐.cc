#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        multiset<int> ms;
        multiset<int>::iterator iter;
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            char com;
            int n;
            cin >> com >> n;
            if (com == 'I') {
                ms.insert(n);
            } else {                          // D 연산
                if (n == 1 && !ms.empty()) {  // D 1
                    iter = ms.find(*ms.rbegin());
                    ms.erase(iter);                   // erase(값)으로 하면 해당 값이 모두 지워져버림. iter 사용 필수 !!
                } else if (n == -1 && !ms.empty()) {  // D -1
                    iter = ms.find(*ms.begin());
                    ms.erase(iter);
                }
            }
        }
        if (ms.empty())
            cout << "EMPTY\n";
        else {
            cout << *ms.rbegin() << " " << *ms.begin() << '\n';
        }
    }
}