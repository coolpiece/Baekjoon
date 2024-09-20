#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "swimming" << " ";
    }
    cout << endl;

    vector<string> v;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        if (!str.compare("bowling"))
            v.push_back("soccer");
        else
            v.push_back("bowling");
    }
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}