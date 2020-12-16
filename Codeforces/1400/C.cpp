#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string k;
        cin >> k;
        int x;
        cin >> x;
        string ans(k.length(), '1');
        bool noSol = false;
        for (int i = 0; i < k.length(); ++i){
            if (k[i] == '0'){
                if (i - x >= 0){
                    ans [i-x] = '0';
                }
                if (i + x < k.length()){
                    ans [i + x] = '0';
                }
            }
        }   
        for (int i = 0; i < k.length(); ++i){
            if (k[i] == '1'){
                if ((i - x < 0 || ans[i - x] == '0') && (i + x >= k.length() || ans[i + x] == '0')){
                    noSol = true;
                    break;
                }
            }
        }
        if (noSol){
            cout << -1 << endl;
            continue;
        }
        cout << ans << endl;
    }
    return 0;
}