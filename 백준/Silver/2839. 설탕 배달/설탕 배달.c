#include <stdio.h>

int main(void) {
	int n, cnt;
	scanf("%d", &n);
	cnt = n / 5;
	n %= 5;
	while (n % 3 != 0 && cnt != 0) {
		n += 5;
		cnt--;
		if (cnt == 0) break;
	}
	
	if (n % 3 == 0) {
		cnt += n / 3;
		printf("%d\n", cnt);
	}
	else printf("-1");
	return 0;
}