#include <stdio.h>
#include <string.h>
int main(void) {
	int n, cnt, line = 0;
	scanf("%d", &n);
	while (1) {
		if (n <= 0) break;
		line++;
		n -= line; // line : 분모 최대값
	}
		cnt = n + line;
	if (line % 2 == 0)
		printf("%d/%d", cnt, 1 - n);
	else
		printf("%d/%d", 1 - n, cnt);

	return 0;
}