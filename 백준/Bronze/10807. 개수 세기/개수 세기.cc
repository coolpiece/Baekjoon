#include <bits/stdc++.h>
using namespace std;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    int n, count = 0;
    cin >> n;
    int input[n];
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }
    int v;
    cin >> v;
    for (int i = 0; i < n; i++) {
        if (input[i] == v) {
            count++;
        }
    }
    cout << count;
}