#include <stdio.h>

int main(void) {
	int t, h, w, n, floor, room;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d %d %d", &h, &w, &n);
		floor = n % h;
		room = n / h + 1;
		if (floor == 0) {
			room--;
			floor = h;
		}
		if (room < 10) printf("%d0%d\n", floor, room);
		else printf("%d%d\n", floor, room);
	}
	return 0;
}