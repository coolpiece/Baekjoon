#include <bits/stdc++.h>
using namespace std;

int main(void) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    long long n;
    cin >> n;
    vector<string> v = {"baby", "sukhwan", "tururu", "turu", "very", "cute", "tururu", "turu", "in", "bed", "tururu", "turu", "baby", "sukhwan"};
    int idx = (n + 13) % 14;
    n = (n + 13) / 14;
    if (!v[idx].compare("tururu")) {
        if (n <= 3) {
            cout << v[idx];
            for (int i = 1; i < n; i++) cout << "ru";
        } else {
            cout << "tu+ru*" << n + 1;
        }
    } else if (!v[idx].compare("turu")) {
        if (n <= 4) {
            cout << v[idx];
            for (int i = 1; i < n; i++) cout << "ru";
        } else {
            cout << "tu+ru*" << n;
        }
    } else
        cout << v[idx];
}