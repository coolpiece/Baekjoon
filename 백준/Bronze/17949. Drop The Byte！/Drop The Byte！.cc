#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    int N, pos = 0;
    cin >> str >> N;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        if (!s.compare("char")) {
            s = str.substr(pos, 2);
            long long tmp = stoll(s, nullptr, 16);
            cout << tmp << " ";
            pos += 2;
        } else if (!s.compare("int")) {
            s = str.substr(pos, 8);
            long long tmp = stoll(s, nullptr, 16);
            cout << tmp << " ";
            pos += 8;
        } else {
            s = str.substr(pos, 16);
            long long tmp = stoll(s, nullptr, 16);
            cout << tmp << " ";
            pos += 16;
        }
    }
}