#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    cin.ignore();
    for (int i = 0; i < t; i++) {
        string str;
        getline(cin, str);

        vector<int> ch(26);
        for (int j = 0; j < str.size(); j++) {
            char c = str[j];
            if (c != ' ') ch[c - 'a']++;
        }
        //for (int j = 0; j < 26; j++) cout << ch[j] << " ";
        //cout << '\n';

        int maxcnt = -1, ans = -1;
        for (int j = 0; j < 26; j++) {
            if(ch[j] > maxcnt) {
                maxcnt = ch[j];
                ans = j;
            }
        }
        for (int j = 0; j < 26; j++) { // 중복값 있는지 확인.
            if(ch[j] == maxcnt && ans != j) {
                maxcnt = -1;
                break;
            }
        }

        if (maxcnt == -1)
            cout << "?\n";
        else
            cout << (char)(ans + 'a') << '\n';
    }
}