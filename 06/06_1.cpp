#include <iostream>
#include <string>
#include <set>

using namespace std;

int main(){
    string s; cin >> s;
    for(int i=0; i<s.size()-13; i++){
        set <char> ss;
        for(int j=0; j<14; j++)
            ss.insert(s[i+j]);
        if(ss.size() == 14){
            cout << i + 14 << '\n';
            return 0;
        }
    }
    return 0;
}