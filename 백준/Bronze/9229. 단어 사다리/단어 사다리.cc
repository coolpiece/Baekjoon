#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string cur;
    int flag = 0;
    while (1) {
        string str;
        cin >> str;
        if (!str.compare("#")) {  // 테스트 케이스의 끝.
            if (flag == -1)
                break;
            else if (flag == 1)
                cout << "Incorrect\n";
            else
                cout << "Correct\n";
            cur.clear();
            flag = -1;
            continue;
        } else if(flag==-1)
            flag = 0;

        if (cur.empty())  // 첫 입력.
            cur = str;
        else {
            if (cur.size() != str.size()) {  // 길이가 다른 경우.
                flag = 1;
                continue;
            }

            int dif = 0;
            for (int i = 0; i < str.size(); i++)
                if (cur[i] != str[i]) dif++;
            if (dif != 1) {  // 한 글자가 바뀌지 않은 경우.
                flag = 1;
                continue;
            }
            cur = str;
        }
    }
}