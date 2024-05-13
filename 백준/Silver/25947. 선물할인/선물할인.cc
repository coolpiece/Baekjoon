// 예산을 모두 사용하지 않아도 됨..
#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, b, a, sum = 0, left = 0, right = 0;
    cin >> n >> b >> a;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());

    for (; right < a; right++) { // 최대한 많이 반값으로 구매.
        sum += v[right] / 2;
        if (sum > b) break;
    }
    if (sum <= b) {
        for (; right < n; right++) {  // 예산을 넘지 않으면 마지막 선물 반 값, 처음 선물 원래 값.
            sum += v[right] / 2;
            sum += v[left] / 2;
            left++;
            if (sum > b) break;
        }
    }
    cout << right;
}