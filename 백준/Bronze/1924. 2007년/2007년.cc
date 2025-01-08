#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x, y, d;
    cin >> x >> y;

    vector<int> v(12);
    v[0] = 1; // 각 월 1일의 요일 저장.
    vector<int> day = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};  // 월별 날짜 수.
    vector<string> week = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    for (int i = 1; i < 12; i++) {
        v[i] = (v[i - 1] + day[i - 1]) % 7;
    }

    d = (v[x - 1] + y - 1) % 7;
    cout << week[d];
}