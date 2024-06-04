#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, s, start = 0, end = -1, len;
    cin >> n >> s;
    vector<int> v(n), sum(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        sum[i] = v[i];
        if (i) sum[i] += sum[i - 1];
        if (sum[i] >= s && end == -1) end = i; // [0]부터 시작했을 때 처음으로 s 이상이 되는 부분 수열의 끝 인덱스 저장.
    }

    if (end == -1) cout << 0; // 불가능하면 0 출력.
    else {
        len = end - start + 1;
        for (int i = end; i < n; i++) {
            while (sum[i] - sum[start] >= s) { // 부분 합이 s보다 크면 start 뒤로 → 부분 수열 길이 줄이기.
                if (len > i - start) len = i - start; // 최소 길이 갱신.
                start++;
            }
        }
        cout << len;
    }
}