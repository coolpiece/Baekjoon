#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    queue<int> q;
    for (int i = 0; i < n; i++) {
        string str;
        int com;
        cin >> str;
        if (!str.compare("push")) {
            cin >> com;
            q.push(com);
        } else if (!str.compare("pop")) {
            if (q.empty())
                cout << -1 << '\n';
            else {
                cout << q.front() << '\n';
                q.pop();
            }
        } else if (!str.compare("size")) {
            cout << q.size() << '\n';
        } else if (!str.compare("empty")) {
            if (q.empty())
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        } else if (!str.compare("front")) {
            if (q.empty())
                cout << -1 << '\n';
            else {
                cout << q.front() << '\n';
            }
        } else if (!str.compare("back")) {
            if (q.empty())
                cout << -1 << '\n';
            else {
                cout << q.back() << '\n';
            }
        }
    }
}