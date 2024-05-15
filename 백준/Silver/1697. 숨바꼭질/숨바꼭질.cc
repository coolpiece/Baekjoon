#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, second = 0;
    cin >> n >> k;
    queue<pair<int, int>> q;
    bool visited[100001] = {
        false,
    };
    q.push({n, second});
    visited[n] = true;
    while(!q.empty()) {
        int cur = q.front().first, cur_s = q.front().second, walk1 = cur + 1, walk2 = cur - 1, tel = 2 * cur;
        q.pop();
        if (cur == k) {
            second = 0;
            break;
        }
        if (walk1 == k || walk2 == k || tel == k) {
            second = cur_s + 1;
            break;
        }

        if (walk1 <= 100000) {  // 최대 범위 안 넘어가도록
            if (!visited[walk1]) {
                visited[walk1] = true;
                q.push({walk1, cur_s + 1});
            }
        }

        if (walk2 >= 0) {  // 최소 범위 안 넘어가도록
            if (!visited[walk2]) {
                visited[walk2] = true;
                q.push({walk2, cur_s + 1});
            }
        }

        if (tel <= 100000) { // 최대 범위 안 넘어가도록
            if (!visited[tel]) {
                visited[tel] = true;
                q.push({tel, cur_s + 1});
            }
        }
    }
    cout << second;
}