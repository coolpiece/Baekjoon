#include <stdio.h>

int main(void) {
	int t, k, n, cnt = 0, room[15][15] = { 0, };
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d", &k);
		scanf("%d", &n);
		if (n == 1) room[k][n]=1;
		else {
			for (int i = 1; i < 15; i++) room[0][i] = i; // 0층
			for (int i = 1; i <= k; i++) { // 1층 ~
				for (int j = 1; j <= n; j++) {
					for (int l = 1; l <= j; l++) cnt += room[i - 1][l];
					room[i][j] = cnt;
					cnt = 0;
				}
			}
		}
		printf("%d\n", room[k][n]);
	}
	return 0;
}