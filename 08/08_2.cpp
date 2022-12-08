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
    int ans = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int cont = 0;
            int aux = 1;
            for(int n_i=i+1; n_i<n; n_i++){
                cont++;
                if(trees[n_i][j] >= trees[i][j]) break;
            }
            aux *= cont;
            cont = 0;
            for(int n_i=i-1; n_i>=0; n_i--){
                cont++;
                if(trees[n_i][j] >= trees[i][j]) break;
            }
            aux *= cont;
            cont = 0;
            for(int n_j=j+1; n_j<m; n_j++){
                cont++;
                if(trees[i][n_j] >= trees[i][j]) break;
            }
            aux *= cont;
            cont = 0;
            for(int n_j=j-1; n_j>=0; n_j--){
                cont++;
                if(trees[i][n_j] >= trees[i][j]) break;
            }
            aux *= cont;
            ans = max(ans, aux);
        }
    }
    cout << ans << endl;
    return 0;
}