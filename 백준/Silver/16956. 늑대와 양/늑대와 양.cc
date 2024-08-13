#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int r, c;
    cin >> r >> c;
    char pasture[r][c];
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> pasture[i][j];
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (pasture[i][j] == 'W') {  // 늑대의 상하좌우에 양이 있으면 0 출력, 종료.
                if (i > 0 && pasture[i - 1][j] == 'S') {
                    cout << 0;
                    return 0;
                }
                if (i < r - 1 && pasture[i + 1][j] == 'S') {
                    cout << 0;
                    return 0;
                }
                if (j > 0 && pasture[i][j - 1] == 'S') {
                    cout << 0;
                    return 0;
                }
                if (j < c - 1 && pasture[i][j + 1] == 'S') {
                    cout << 0;
                    return 0;
                }
            }
        }
    }

    cout << 1 << '\n';
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (pasture[i][j] == '.')  // .을 모두 울타리로 바꿔서 출력.
                cout << 'D';
            else
                cout << pasture[i][j];
        }
        cout << '\n';
    }
}