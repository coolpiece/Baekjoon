#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int r, c, n;
    cin >> r >> c >> n;
    vector<vector<int>> xpos(n + 1);
    vector<vector<int>> ypos(n + 1);
    vector<long long> s;

    for (int i = 0; i < n; i++) {
        int a, v, h;
        cin >> a >> v >> h;
        xpos[a].push_back(v);  // xpos[유물 번호]에 x좌표 저장.
        ypos[a].push_back(h);  // ypos[유물 번호]에 y좌표 저장.
    }

    for (int i = 1; i <= n; i++) {
        long long x1, x2, y1, y2, size;
        if (xpos[i].empty()) {
            s.push_back(0);
            continue;
        }
        sort(xpos[i].begin(), xpos[i].end());  // x좌표 정렬 후, 최솟값, 최댓값 찾기.
        x1 = xpos[i][0];
        x2 = xpos[i][xpos[i].size() - 1];
        sort(ypos[i].begin(), ypos[i].end());  // y좌표 정렬 후, 최솟값, 최댓값 찾기.
        y1 = ypos[i][0];
        y2 = ypos[i][ypos[i].size() - 1];

        size = (abs(x1 - x2) + 1) * (abs(y1 - y2) + 1);
        s.push_back(size);
    }

    long long num, size = 0;
    for (int i = 0; i < s.size(); i++) {
        if(size<s[i]) {
            size = s[i];
            num = i;
        }
    }
    cout << num + 1 << " " << size;
}