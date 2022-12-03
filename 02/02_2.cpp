#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int convert_1(char x){
    int ans = (int)(x-'A');
    return ans;
}

int convert_2(int x, char y){
    if(y == 'Y') return x;
    if(y == 'Z') return (x+1)%3;
    if(y == 'X') return (x+2)%3;
}

int compare(int x, int y){
    // 1 -> rock, 2 -> paper, 3 -> scissors
    if(x == y) return 3;
    if(x == 1 && y == 2) return 6;
    if(x == 2 && y == 3) return 6;
    if(x == 3 && y == 1) return 6;
    return 0;  
}

int main(){
    char p1, p2;
    ll ans = 0;
    while(cin >> p1 >> p2){
        int P1 = convert_1(p1);
        int P2 = convert_2(P1, p2);
        P1++; P2++;
        int cur = 0; cur += P2;
        cur += compare(P1, P2);
        ans += cur;
    }
    cout << ans << '\n';
    return 0;
}