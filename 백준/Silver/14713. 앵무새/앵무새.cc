#include <bits/stdc++.h>
using namespace std;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    int n;
    string input;
    cin >> n;
    vector<queue<string>> q(n + 1);
    getline(cin, input); // 개행 문자 지우기.

    for (int i = 0; i < n + 1; i++) {
        getline(cin, input);
        stringstream ss(input);
        string word;
        while (getline(ss, word, ' ')) {
            q[i].push(word);
        }
    }
    int size = q[n].size();
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < n; j++) {
            if (!q[j].empty() && !q[n].front().compare(q[j].front())) { // 같은 경우.
                q[n].pop();
                q[j].pop();
                break;
            }
        }
        if (q[n].size() == size - i) {
            cout << "Impossible\n";
            break;
        }
    }
    if (q[n].empty()) {
        int err = 0;
        for (int i = 0; i < n; i++) {
            if (!q[i].empty()) {
                cout << "Impossible\n";
                err = 1;
                break;
            }
        }
        if(!err)
            cout << "Possible\n";
    }
}