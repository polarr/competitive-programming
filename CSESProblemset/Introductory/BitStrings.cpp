#include <bits/stdc++.h>

using namespace std;

int main(){
    int x;
    cin >> x;
    int ans = 1;
    for (int i = 0; i < x; ++i){
        ans *= 2;
        ans %= 1000000007;
    }
    cout << ans;
    return 0;
}