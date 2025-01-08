#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    stack<int> s;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int com;
        cin >> com;
        switch (com) {
            case 1:
                cin >> x;
                s.push(x);
                break;
            case 2:
                if (s.empty())
                    cout << -1 << '\n';
                else {
                    cout << s.top() << '\n';
                    s.pop();
                }
                break;
            case 3:
                cout << s.size() << '\n';
                break;
            case 4:
                if (s.empty())
                    cout << 1 << '\n';
                else
                    cout << 0 << '\n';
                break;
            case 5:
                if (s.empty())
                    cout << -1 << '\n';
                else
                    cout << s.top() << '\n';
                break;
        }
    }
}