#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    if (n % 2) {
        for (int i = 0; i < n; i++) cout << '*';
        cout << '\n';
        for (int i = 0; i < n / 2; i++) cout << ' ';
        cout << "*\n";
        for (int i = n / 2; i > 0; i--) {
            for (int j = 0; j < i - 1; j++) cout << ' ';
            cout << '*';
            for (int j = 0; j < n - 2 * i; j++) cout << ' ';
            cout << "*\n";
        }
    } else
        cout << "I LOVE CBNU";
}