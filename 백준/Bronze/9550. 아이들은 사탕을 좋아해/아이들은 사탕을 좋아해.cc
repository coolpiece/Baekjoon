#include <bits/stdc++.h>
using namespace std;

int main(void) {
ios_base::sync_with_stdio(false);
cin.tie(NULL);

    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int N, K, child = 0;
        cin >> N >> K;
        for (int i = 0; i < N; i++) {
            int candy;
            cin >> candy;
            child += candy / K;
        }
        cout << child << '\n';
    }
}