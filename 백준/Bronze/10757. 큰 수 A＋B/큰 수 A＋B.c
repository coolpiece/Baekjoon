#include <stdio.h>
#include <string.h>

void StringReverse(char* str);

int main(void) {
	char a[10001] = { 0 }, b[10001] = { 0 }, c[10002] = { 0 };
	int length, carry = 0;
	scanf("%s %s", a, b);
	StringReverse(a);
	StringReverse(b);
	if (strlen(a) > strlen(b)) length = strlen(a);
	else length = strlen(b);
	for (int i = 0; i < length; i++) {
		if (a[i] == '\0') a[i] = '0';
		if (b[i] == '\0') b[i] = '0';
		c[i] = a[i] - '0' + b[i] - '0' + carry;
		if (c[i] >= 10) {
			carry = 1;
			c[i] -= 10;
		}
		else carry = 0;
		c[i] += '0';
	}
	if (carry == 1) c[length] = '1';
	StringReverse(c);
	printf("%s", c);
	return 0;
}

void StringReverse(char* str) {
	char temp;
	int length = strlen(str);
	for (int i = 0; i < length/2; i++) {
		temp = *(str + i);
		*(str + i) = *(str + length - 1 - i);
		*(str + length - 1 - i) = temp;
	}
}