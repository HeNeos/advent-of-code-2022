#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector <string> separate(string s, char delimiter){
    vector <string> ans;
    int position = s.find(delimiter);
    ans.push_back(s.substr(0, position));
    ans.push_back(s.substr(position + 1, s.size() - position - 1));
    return ans;
}

int main(){
    string s;
    int ans = 0;
    while(cin >> s){
        bool isContained = false;
        vector <string> p = separate(s, ',');
        vector <string> p1 = separate(p[0], '-');
        vector <string> p2 = separate(p[1], '-');
        int l1 = stoi(p1[0]); int r1 = stoi(p1[1]);
        int l2 = stoi(p2[0]); int r2 = stoi(p2[1]);
        if(l2 <= l1 && r2 >= r1) isContained = true;
        if(l1 <= l2 && r1 >= r2) isContained = true;
        if(isContained) ans++;
    }
    cout << ans << '\n';
    return 0;
}