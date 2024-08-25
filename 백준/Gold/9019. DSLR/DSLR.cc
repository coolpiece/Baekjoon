#include <bits/stdc++.h>
using namespace std;

int fun(char command, int n) {
    if (command == 'D') {
        n *= 2;
        n %= 10000;
    }

    else if (command == 'S') {
        n--;
        if (n < 0) n = 9999; // n이 0이면 음수가 됨.
    }

    else if (command == 'L') {
        n = (n % 1000) * 10 + n / 1000;
    }

    else if (command == 'R') {
        n = (n % 10) * 1000 + n / 10;
    }
    return n;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for (int j = 0; j < t; j++) {
        int a, b;
        cin >> a >> b;
        bool visited[10001];
        fill(&visited[0], &visited[10001], false);
        queue<pair<int, string>> q;
        q.push({a, ""});
        while (!q.empty()) {
            int n = q.front().first;
            string comm = q.front().second;
            // cout << "cur: " << comm << ", " << n << '\n';
            q.pop();
            if (n == b) {
                cout << comm << '\n';
                break;
            }
            int d = fun('D', n), s = fun('S', n), l = fun('L', n), r = fun('R', n);
            if (!visited[d]) {
                q.push({d, comm + 'D'});
                visited[d] = true;
            }
            if (!visited[s]) {
                q.push({s, comm + 'S'});
                visited[s] = true;
            }
            if (!visited[l]) {
                q.push({l, comm + 'L'});
                visited[l] = true;
            }
            if (!visited[r]) {
                q.push({r, comm + 'R'});
                visited[r] = true;
            }
        }
    }
}