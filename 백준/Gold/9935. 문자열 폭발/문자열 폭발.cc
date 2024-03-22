#include <bits/stdc++.h>
using namespace std;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);

    string input, pung, s;
    cin >> input >> pung;

    int length = input.size();

    for (int i = 0; i < length; i++) {
        s.push_back(input[i]);
        if(s.size() >= pung.size()) {
            if(s.back() == pung.back()) { // 문자열 맨 뒤의 문자 비교.
                string tmp = s.substr(s.size() - pung.size(), pung.size()); // 문자열 s의 맨 뒤에서 pung의 개수만큼 읽어서 비교.
                if(!tmp.compare(pung)) { // 같으면 삭제.
                    s.erase(s.size() - pung.size(), pung.size());
                }
            }
        }
    }

    if (s.empty()) cout << "FRULA";
    else
        cout << s;
}