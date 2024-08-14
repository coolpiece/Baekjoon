#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string n;
    vector<int> v(9);
    cin >> n;

    int len = n.size();
    for (int i = 0; i < len; i++) {
        int num = n[i] - '0';
        if (num == 9)
            v[6]++;
        else
            v[num]++;
    }
    v[6] += 1;
    v[6] /= 2;  // 6과 9는 같이 사용 가능하므로, 절반만 있어도 됨.

    int set = *max_element(v.begin(), v.end());
    cout << set;
}