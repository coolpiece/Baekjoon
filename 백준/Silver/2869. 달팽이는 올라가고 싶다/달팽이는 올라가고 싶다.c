#include <stdio.h>

int main(void) {
	int a, b, v, cnt;
	scanf("%d %d %d", &a, &b, &v);
	if (a == v) cnt = 1;
	else {
		cnt = (v - a) / (a - b) + 1;
		if ((v - a) % (a - b) != 0)
			cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}