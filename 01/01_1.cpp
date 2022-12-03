#include <iostream>
#include <string>

using namespace std;

int main(){
    string s;
    long long sum = 0;
    long long ans = 0;
    int indx = 0;
    int i = 0;
    while(getline(cin, s)){
        if(s.size() == 0){
            if(sum > ans){
                ans = sum;
                indx = i;
            }
            sum = 0;
            i++;
        }
        else
            sum += stoll(s);
    }
    cout << ans << '\n';
    return 0;
}