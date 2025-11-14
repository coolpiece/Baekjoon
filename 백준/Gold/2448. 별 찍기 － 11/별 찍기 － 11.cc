#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> v(3080, vector<char>(6150, ' '));
void star(int x, int y, int h) {
    if (h == 3) {
        v[x][y] = '*';
        v[x + 1][y - 1] = '*';
        v[x + 1][y + 1] = '*';
        for (int i = 0; i < 5; i++) v[x + 2][y - 2 + i] = '*';
    } else {
        star(x, y, h / 2);
        star(x + h / 2, y - h / 2, h / 2);
        star(x + h / 2, y + h / 2, h / 2);
    }
}

int main(void) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, width, height;
    cin >> n;
    height = n;
    width = (n / 3) * 6 - 1;

    star(0, width / 2, n);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) cout << v[i][j];
        cout << '\n';
    }
}