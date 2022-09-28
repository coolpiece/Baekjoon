#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);
	
	int input[5], sum = 0;
	for (int i = 0; i < 5; i++) {
		cin >> input[i];
		sum += input[i] * input[i];
	}
	cout << sum % 10;
}