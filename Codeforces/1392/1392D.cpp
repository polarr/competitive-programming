#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--){
        int x;
        cin >> x;
        string s;
        cin >> s;
        int ans = 0;
        for (int i = 0; i < x; ++i){
            int p = i - 1 < 0 ? x - 1: i - 1;
            int n = i + 1 % x;
            if (s[p] != s[n]){
                continue;
            }
            if (s[p] == 'R'){
                if (s[i] == 'L'){
                    continue;
                }

                ans ++;
                s[i] == 'L';
            }
            else{
                if (s[i] == 'R'){
                    continue;
                }

                ans ++;
                s[i] == 'R';
            }
        }

        cout << ans << endl;
    }
    return 0;
}