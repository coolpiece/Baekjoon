#include <stdio.h>
#include <string.h>
int main(void) {
	int n, i = 0, cnt = 1;
	scanf("%d", &n);
	while (1) {
		if (n <= 1) {
			printf("%d", cnt);
			break;
		}
		i += 6;
		n -= i;
		cnt++;
	}
	return 0;
}