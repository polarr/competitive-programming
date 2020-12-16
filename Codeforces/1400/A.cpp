#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int x;
        cin >> x;
        string k;
        cin >> k;
        string ans = "";
        for (int i = 0; i < 2 * x - 1; i += 2){
            ans += k[i];
        }
        cout << ans << endl;
    }
    return 0;
}