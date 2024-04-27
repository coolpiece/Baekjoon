#include <bits/stdc++.h>
using namespace std;
void dfs(bool arr[][50], bool visited[][50], int x, int y);
bool visited[50][50] = {
    false,
};
bool arr[50][50] = {
    false,
};

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int m, n, k, count = 0;
        cin >> m >> n >> k;
        for (int j = 0; j < k; j++) {
            int x, y;
            cin >> x >> y;
            arr[x][y] = 1;
        }
        for (int j = 0; j < 50; j++) {
            for (int l = 0; l < 50; l++) {
                if (arr[j][l] && !visited[j][l]) { // 배추가 있는 방문하지 않은 좌표.
                    dfs(arr, visited, j, l);
                    count++;
                }
            }
        }
        cout << count << '\n';

        for (int i = 0; i < 50; i++) { // 메모리 초기화.
            memset(visited[i], false, sizeof(bool) * 50);
            memset(arr[i], false, sizeof(bool) * 50);
        }
    }
}

void dfs(bool arr[][50], bool visited[][50], int x, int y) {
    visited[x][y] = 1;
    if(x && arr[x - 1][y] && !visited[x-1][y]) dfs(arr, visited, x - 1, y);  // x 좌표 값이 0이 아닐 때.
    if ((x < 49) && arr[x + 1][y] && !visited[x + 1][y]) dfs(arr, visited, x + 1, y);
    if (y && arr[x][y - 1] && !visited[x][y - 1]) dfs(arr, visited, x, y - 1);  // y 좌표 값이 0이 아닐 때.
    if ((y < 49) && arr[x][y + 1] && !visited[x][y + 1]) dfs(arr, visited, x, y + 1);
}