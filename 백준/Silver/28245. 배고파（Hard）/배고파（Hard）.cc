#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, m;
    cin >> n;
    map<long long, pair<int, int>> ma;
    for (int i = 0; i <= 60; i++) {
        for (int j = 0; j <= i; j++) {
            long long tmp = (1LL << i) + (1LL << j);  // 비트연산으로 2의 제곱 수 만들기.
            ma[tmp] = pair<int, int>(j, i);
        }
    }

    map<long long, pair<int, int>>::iterator iter, lower, upper;
    for (int i = 0; i < n; i++) {
        cin >> m;
        if ((iter = ma.find(m)) != ma.end())  // 존재하는 경우.
            cout << iter->second.first << " " << iter->second.second << '\n';
        else {  // 존재하지 않는 경우 가장 가까운 값 찾기.
            lower = ma.upper_bound(m);
            if (lower != ma.begin()) {
                upper = lower--;  // iter2: m보다 큰 값, iter: m보다 작은 값

                if (abs(lower->first - m) <= abs(upper->first - m)) {  // m보다 작은 값이 더 가까운 경우.
                    cout << lower->second.first << " " << lower->second.second << '\n';
                } else {  // m보다 큰 값이 더 가까운 경우.
                    cout << upper->second.first << " " << upper->second.second << '\n';
                }
            } else
                cout << 0 << " " << 0 << '\n';
        }
    }
}