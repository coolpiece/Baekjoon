#include <bits/stdc++.h>
using namespace std;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    int n, m, input;
    long long score = 0, a, b;
    priority_queue <long long, vector <long long>, greater <long long>> q;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> input;
        q.push(input);
    }

    for (int i = 0; i < m; i++) {
        a = q.top();
        q.pop();
        b = q.top();
        q.pop();
        q.push(a + b);
        q.push(a + b);
    }

    while(!q.empty()) {
        score += q.top();
        q.pop();
    }
    cout << score << '\n';
}