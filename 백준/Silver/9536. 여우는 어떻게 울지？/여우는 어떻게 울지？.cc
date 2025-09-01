#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    cin.ignore(); // 개행 제거.
    for (int t = 0; t < T; t++) {
        string str, tmp;
        vector<string> v;
        getline(cin, str);
        stringstream ss(str);
        while (ss >> tmp) v.push_back(tmp); // 단어 단위로 분리해서 벡터에 저장.

        while (getline(cin, str)) {
            if (!str.compare("what does the fox say?")) // 마지막 줄인 경우.
                break;
            else {
                stringstream ss(str);
                string ani, goes, say;
                ss >> ani >> goes >> say;
                for (int i = 0; i < v.size(); i++) {
                    if (!v[i].compare(say)) v[i] = ""; // 다른 울음소리 제거.
                }
            }
        }
        for (int i = 0; i < v.size(); i++) {
            if (v[i].empty())
                continue;
            else
                cout << v[i] << " ";
        }
        cout << '\n';
    }
}