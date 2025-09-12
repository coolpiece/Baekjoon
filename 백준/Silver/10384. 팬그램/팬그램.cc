#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        string str;
        getline(cin, str);
        vector<int> v(26);
        for (int i = 0; i < str.size(); i++) {
            if (str[i] >= 'a' && str[i] <= 'z')
                v[str[i] - 'a']++;
            else if (str[i] >= 'A' && str[i] <= 'Z')
                v[str[i] - 'A']++;
        }

        int m = 4;
        for (int i = 0; i < 26; i++) m = min(m, v[i]);
        cout << "Case " << i + 1 << ": ";
        if (m == 3)
            cout << "Triple pangram!!!\n";
        else if (m == 2)
            cout << "Double pangram!!\n";
        else if (m == 1)
            cout << "Pangram!\n";
        else
            cout << "Not a pangram\n";
    }
}