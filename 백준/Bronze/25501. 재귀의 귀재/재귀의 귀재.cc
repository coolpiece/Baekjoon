#include <stdio.h>
#include <string.h>

int count = 0;

int recursion(const char* s, int l, int r) {
    count++;
    if (l >= r) return 1;
    else if (s[l] != s[r]) return 0;
    else return recursion(s, l + 1, r - 1);
}

int isPalindrome(const char* s) {
    return recursion(s, 0, strlen(s) - 1);
}

int main() {
    char input[1005];
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%s", input);
        int cnt = isPalindrome(input);
        printf("%d %d\n", cnt, count);
        count = 0;
    }
}