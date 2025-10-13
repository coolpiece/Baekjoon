#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    int k = 1;
    cin >> str;
    for (int i = 1; i < str.size(); i++) {
        if (str[i - 1] >= str[i]) k++;
    }
    cout << k;
}