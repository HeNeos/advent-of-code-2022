#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int max(int a, int b){
    if(a < b) return b;
    else return a;
}

int main(){
    string s;
    ll sum = 0;
    vector <ll> elves;
    while(getline(cin, s)){
        if(s.size() == 0){
            elves.push_back(sum);
            sum = 0;
        }
        else sum += stoll(s);
    }
    sort(elves.begin(), elves.end());
    ll ans = 0;
    for(int i=elves.size()-1; i>=max(0, elves.size()-3); i--)
        ans += elves[i];
    cout << ans << '\n';
    return 0;
}