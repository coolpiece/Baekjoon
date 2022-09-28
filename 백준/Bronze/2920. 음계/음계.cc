#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);
	
	int list[8], check = 0;
	for (int i = 0; i < 8; i++) cin >> list[i];
	if (list[0] == 1) {
		int i = 0;
		while (i <= 8) {
			if (list[i] == i + 1) i++;
			else break;
			if (i == 8) {
				cout << "ascending";
				check = 1;
				break;
			}
		}
	}

	else if (list[0] == 8) {
		int i = 8;
		while (i > 0) {
			if (list[8 - i] == i) i--;
			else break;
			if (i == 0) {
				cout << "descending";
				check = 1;
				break;
			}
		}
	}
	if (check == 0) cout << "mixed";
}