/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-09-29
 * Contest: Codeforces 2020
 * Problem: C
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    ull x, y, z; cin >> x >> y >> z;
    bitset<61> b(x), c(y), d(z); 
    bitset<61> ans;
    for (int i = 0; i < 61; i++){
        //cout << d[i] << " ";
        if (d[i] == 0){
            if (b[i] == 1 && c[i] == 1){
                ans[i] = 1;
            } else if (b[i] == 0){
                ans[i] = 0;
            }
            else {
                cout << -1 << endl;
                return;
            }
        } else {
            if (b[i] == 1){
                ans[i] = 0;
            } else if (b[i] == 0 && c[i] == 0){
                ans[i] = 1;
            } else {
                cout << -1 << endl;
                return;
            }
        }
    }

    cout << ans.to_ullong() << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; ++t){
        // cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}