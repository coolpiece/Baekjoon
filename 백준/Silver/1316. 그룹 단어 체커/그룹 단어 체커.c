#include <stdio.h>
#include <string.h>

int main(void) {
	char word[100], ch;
	int n, wrong = 0, count = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", word);
		for (int j = 0; j < strlen(word); j++) {
			for (int k = j+1; k < strlen(word); k++) {
				if (word[j] == word[k]) {
					if (k - j == 1) break;
					else wrong++;
				}
			}
		}
		if (wrong == 0) count++;
		wrong = 0;
	}
		printf("%d", count);
	return 0;
}