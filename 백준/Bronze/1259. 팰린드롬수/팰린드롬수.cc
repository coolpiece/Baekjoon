#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);
	
	string str;
	while (1) {
		cin >> str;
		int leg = str.length(), check = 1;
		for (int i = 0; i < leg / 2; i++) {
			if (str[i] != str[leg - i - 1]) {
				check = 0;
				break;
			}
		}
		if (str == "0") break;
		if (check == 0) cout << "no\n";
		else cout << "yes\n";
	}
}