#include<bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
    
	int n, k;
	cin >> n >> k;
	vector<int> maxScore(k); // 요소 별 최댓값 저장.
	vector<int> person(k, -1); // 요소 별 최대 점수인 사람.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			int tmp;
			cin >> tmp;
			if (maxScore[j] < tmp) {
				maxScore[j] = tmp;
				person[j] = i;
			}
			else if (maxScore[j] == tmp)
				person[j] = -1;
		}
	}
	set<int> num;
	for (int i = 0; i < k; i++)
		if (person[i] != -1) num.insert(person[i]);
	cout << num.size();
	return 0;
}