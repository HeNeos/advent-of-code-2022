#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main(){
    int ans = 0;
    string s;
    while(cin >> s){
        int sz = s.size();
        vector <int> value_1(52);
        vector <int> value_2(52);
        for(int i=0; i<sz/2; i++){
            int c1 = s[i] - 'a';
            int c2 = s[i + sz/2] - 'a';
            if(c1 < 0) c1 = 26 + s[i] - 'A';
            if(c2 < 0) c2 = 26 + s[i + sz/2] - 'A';
            value_1[c1]++;
            value_2[c2]++;   
        }
        for(int i=0; i<52; i++){
            if(value_1[i] >= 1 && value_2[i] >= 1){
                ans += (i+1);
                break;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}