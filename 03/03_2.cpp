#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main(){
    int ans = 0;
    string s1, s2, s3;
    while(cin >> s1 >> s2 >> s3){
        vector <int> value_1(52);
        vector <int> value_2(52);
        vector <int> value_3(52);
        for(int i=0; i<s1.size(); i++){
            int c = s1[i] - 'a';
            if(c < 0) c = 26 + s1[i] - 'A';
            value_1[c]++; 
        }
        for(int i=0; i<s2.size(); i++){
            int c = s2[i] - 'a';
            if(c < 0) c = 26 + s2[i] - 'A';
            value_2[c]++; 
        }
        for(int i=0; i<s3.size(); i++){
            int c = s3[i] - 'a';
            if(c < 0) c = 26 + s3[i] - 'A';
            value_3[c]++; 
        }
        for(int i=0; i<52; i++){
            if(value_1[i] >= 1 && value_2[i] >= 1 && value_3[i] >= 1){
                ans += (i+1);
                break;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}