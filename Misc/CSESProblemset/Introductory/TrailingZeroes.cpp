#include <bits/stdc++.h>

using namespace std;

int main(){
    int x;
    cin >> x;
    int mx = floor(log(x)/log(5));
    int ans = 0;
    int fivem = 5;
    for (int i = 1; i <= mx; ++i){
        ans += floor(x/fivem);
        fivem *= 5;
    }
    cout << ans;
    return 0;
}