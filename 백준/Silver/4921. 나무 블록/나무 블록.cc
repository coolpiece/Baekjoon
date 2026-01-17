#include <bits/stdc++.h>
using namespace std;

int main (void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    int idx = 1;
    while(cin >> str) {
        int len = str.size(), five = 0, flag = 0;
        if(!str.compare("0")) break;
        if(str[0] != '1' || str[len-1] != '2') {
            cout<<idx<<". NOT\n";
            idx++;
            continue;
        }
        for(int i=1; i < len; i++) {
            if(str[i]=='1') {
                flag = 1;
                break;
            }
            else if(str[i]=='2') {
                if(i == len-1 && str[i-1]!='4' && str[i-1]!='6') {
                    flag = 1;
                    break;
                }

            }
            else if(str[i]=='2') {
                if(str[i-1]!='4' && str[i-1]!='6') {
                    flag = 1;
                    break;
                }

            }
            else if(str[i]=='3') {
                if(str[i-1]!='4' && str[i-1]!='6') {
                    flag = 1;
                    break;
                }

            }
            else if(str[i]=='4') {
                if(str[i-1]!='1' && str[i-1]!='3') {
                    flag = 1;
                    break;
                }
            }
            else if(str[i]=='5') {
                five++;
                if(str[i-1]!='1' && str[i-1]!='3') {
                    flag = 1;
                    break;
                }
            }
            else if(str[i]=='6') {
                five--;
                if(str[i-1]!='8') {
                    flag = 1;
                    break;
                }
            }
            else if(str[i]=='7') {
                if(str[i-1]!='8') {
                    flag = 1;
                    break;
                }
            }
            else if(str[i]=='8') {
                if(str[i-1]!='5' && str[i-1]!='7') {
                    flag = 1;
                    break;
                }
            }
        }
        if(flag || five) {
            cout<<idx<<". NOT\n";
            idx++;
            continue;
        }
        cout<<idx<<". VALID\n";
        idx++;
    }
}