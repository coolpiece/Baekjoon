#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    map<string, int> m;
    for (int i = 0; i<n; i++) {
        string str;
        cin >> str;
        sort(str.begin(), str.end());
        m[str]++;
    }
    cout << m.size();
}