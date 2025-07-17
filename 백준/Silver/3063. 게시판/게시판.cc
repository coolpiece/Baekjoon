#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int x1, y1, x2, y2, x3, y3, x4, y4, w, x, y;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        w = (x2 - x1) * (y2 - y1);

        if (x2 <= x3 || x4 <= x1)
            x = 0;  // 겹치지 않는 경우.
        else if (x1 <= x3 && x4 <= x2)
            x = x4 - x3;  // 완전히 기존 포스터 안으로 들어간 경우.
        else if (x1 <= x3 && x3 <= x2)
            x = x2 - x3;  // 왼쪽 일부만 겹치는 경우.
        else if (x1 <= x4 && x4 <= x2)
            x = x4 - x1;  // 오른쪽 일부만 겹치는 경우.
        else
            x = x2 - x1;  // 기존 포스터를 완전히 덮은 경우.

        if (y2 <= y3 || y4 <= y1)
            y = 0;  // 겹치지 않는 경우.
        else if (y1 <= y3 && y4 <= y2)
            y = y4 - y3;  // 완전히 기존 포스터 안으로 들어간 경우.
        else if (y1 <= y3 && y3 <= y2)
            y = y2 - y3;  // 아래쪽 일부만 겹치는 경우.
        else if (y1 <= y4 && y4 <= y2)
            y = y4 - y1;  // 위쪽 일부만 겹치는 경우.
        else
            y = y2 - y1;  // 기존 포스터를 완전히 덮은 경우.
        cout << w - x * y << '\n';
    }
}