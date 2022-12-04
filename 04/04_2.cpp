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
        bool isOverlapping= false;
        vector <string> p = separate(s, ',');
        vector <string> p1 = separate(p[0], '-');
        vector <string> p2 = separate(p[1], '-');
        int l1 = stoi(p1[0]); int r1 = stoi(p1[1]);
        int l2 = stoi(p2[0]); int r2 = stoi(p2[1]);
        if(l2 <= r1 && r2 >= l1) isOverlapping = true;
        if(l1 <= r2 && r1 >= l2) isOverlapping = true;
        if(isOverlapping) ans++;
    }
    cout << ans << '\n';
    return 0;
}