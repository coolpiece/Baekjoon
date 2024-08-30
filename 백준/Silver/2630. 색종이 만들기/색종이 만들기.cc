#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> v(128, vector<int>(128));
int white, blue;

void fun(int x, int y, int size) {
    //cout << "x: " << x << ", y: " << y << ", size: "<<size<<" / " << blue <<" "<< white << '\n';
    int num = v[x][y], flag = 1;  // 첫번째 숫자가 그 영역의 색 결정.

    for (int i = x; i < x+size; i++) {
        for (int j = y; j < y+size; j++) {
            if (v[i][j] != num) {  // 다른 색이면 더 분할.
                flag = 0;
                fun(x, y, size / 2);
                fun(x, y + size / 2, size / 2);
                fun(x + size / 2, y, size / 2);
                fun(x + size / 2, y + size / 2, size / 2);
                break;
            }
        }
        if (!flag) break;
    }
    if (flag) {  // 영역이 모두 같은 색이면 카운트.
        if (num == 1)
            blue++;
        else
            white++;
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> v[i][j];
    }
    fun(0, 0, n);

    cout << white << '\n' << blue;
}