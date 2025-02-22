#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(int a=0; a<commands.size(); a++) {
        int i = commands[a][0], j=commands[a][1], k=commands[a][2];
        vector<int> v = array;
        v.erase(v.begin()+j, v.end()); // 뒤 먼저 자르고
        v.erase(v.begin(), v.begin()+i-1); // 앞 자르기
        sort(v.begin(), v.end()); // 정렬
        answer.push_back(v[k-1]);
    }
    return answer;
}