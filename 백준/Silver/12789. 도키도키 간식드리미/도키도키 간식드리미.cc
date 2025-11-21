#include <bits/stdc++.h>
using namespace std;

int main(void) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    stack<int> s;
    int n, cur = 1;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    for (int i = 0; i < n; i++) {
        s.push(v[i]);
        while (!s.empty() && s.top() == cur) {
            s.pop();
            cur++;
        }
    }
    if (s.empty())
        cout << "Nice";
    else
        cout << "Sad";
}