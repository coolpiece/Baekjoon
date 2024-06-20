#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (1) {
        int n;
        cin >> n;
        if (!n) break;
        string str;
        cin >> str;
        vector<int> page(1001);
        fill(page.begin(), page.end(), 0);

        // 범위 구분하기
        string del = ",";  // 구분자
        str += del;        // 문자열의 마지막에 구분자 추가
        vector<string> v;

        int cur_pos = 0;
        int pos;
        while ((pos = str.find(del, cur_pos)) != string::npos) {
            v.push_back(str.substr(0, pos));
            str.erase(0, pos + del.length());
        }

        for (int i = 0; i < v.size(); i++) {
            stringstream ss(v[i]);
            int low, high;
            char dash;
            if (v[i].find('-') != string::npos) {  // 숫자 범위인 경우.
                ss >> low >> dash >> high;
                if (low > high) continue;
                else
                    if(high>1000)
                    high = 1000;
                    for (int j = low; j <= high; j++) {
                        page[j] = 1;
                    }
            } else {  // 단일 숫자인 경우.
                ss >> low;
                if (low > n) continue;
                page[low] = 1;
            }
        }

        int paper = 0;
        for (int i = 1; i <= n; i++) {
            if (page[i]) paper++;
        }
        cout << paper << '\n';
    }
}