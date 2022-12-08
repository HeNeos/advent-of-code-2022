#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector <int> process(string s){
    vector <int> ans;
    for(int i=0; i<s.size(); i++){
        ans.push_back((int)(s[i] - '0'));
    }
    return ans;
}

int main(){
    string s;
    vector <vector <int> > trees;
    while(cin >> s){
        vector <int> t = process(s);
        trees.push_back(t);
    }
    int n = trees.size();
    int m = trees[0].size();
    int ans[n][m];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++)
            ans[i][j] = 0;
    }
    for(int i=0; i<n; i++){
        int maxi = -1;
        for(int j=0; j<m; j++){
            if(trees[i][j] > maxi) ans[i][j]++;
            maxi = max(maxi, trees[i][j]);
        }
        maxi = -1;
        for(int j=m-1; j>=0; j--){
            if(trees[i][j] > maxi) ans[i][j]++;
            maxi = max(maxi, trees[i][j]);
        }
    }
    for(int j=0; j<m; j++){
        int maxi = -1;
        for(int i=0; i<n; i++){
            if(trees[i][j] > maxi) ans[i][j]++;
            maxi = max(maxi, trees[i][j]);
        }
        maxi = -1;
        for(int i=n-1; i>=0; i--){
            if(trees[i][j] > maxi) ans[i][j]++;
            maxi = max(maxi, trees[i][j]);
        }
    }
    int c = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(ans[i][j] != 0)
                c++;
        }
    }
    cout << c << endl;
    return 0;
}