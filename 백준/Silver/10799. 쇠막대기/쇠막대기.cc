#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	stack<char> s;
	string str;
	int num = 0;
	getline(cin, str);
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(' && str[i + 1] == ')') { // 레이저
			i++;
			num += s.size();
		}
		else { // 쇠막대기
			s.push(str[i]);
			if (s.top() == ')') {
				s.pop();
				s.pop();
				num++;
			}
		}
	}
	cout << num;
}