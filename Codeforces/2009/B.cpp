/**
 * Solution by 1egend (polarity.sh)
 * Date: 
 * Contest: 
 * Problem: 
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    vector<int> ans;
    int n; cin >> n;

    for (int i = 0; i < n; i++){
        string x;
        cin >> x;
        for (int i = 0; i < 4; i++){
            if (x[i] == '#'){
                ans.pb(i + 1);
                continue;
            }
        }
    }

    reverse(ans.begin(), ans.end());

    for (int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }

    cout << endl;
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