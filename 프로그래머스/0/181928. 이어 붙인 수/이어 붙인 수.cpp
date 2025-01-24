#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int answer = 0;
    int odd = 0, even = 0;
    for(int i=0; i<num_list.size(); i++) {
        if(num_list[i] % 2) // 홀수
            odd = odd * 10 + num_list[i];
        else // 짝수
            even = even * 10 + num_list[i];
    }
    answer = odd + even;
    return answer;
}