#include <bits/stdc++.h>
using namespace std;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    int n;
    set<string> s;
    set<string>::reverse_iterator iter;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string name, command;
        cin >> name >> command;
        if (!command.compare("enter")) {
            s.insert(name);
        }
        if (!command.compare("leave")) {
            s.erase(s.find(name));
        }
    }
    for (iter = s.rbegin(); iter != s.rend(); iter++) {
        cout << *iter << '\n';
    }
}