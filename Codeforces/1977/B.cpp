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
    ll x; cin >> x;
    vector<int> binary;

    while(x > 0){
        if (x % 2 == 0){
            binary.pb(0);
        } else {
            binary.pb(1);
        }

        x /= 2;
    }

    vector<int> ans(binary.size() + 2);

    int lastIndex = -1;
    for (int i = 0; i < binary.size(); i++){
        int l = binary[i];
        if (l == 0){
            if (lastIndex == -1){
                ans[i] = 0;
            } else {
                if ((i - lastIndex) == 1){
                    ans[i] = 0;
                    ans[lastIndex] = 1;
                } else {
                    ans[i] = 1;
                    ans[lastIndex] = -1;
                }
                lastIndex = -1;
            }
        } else if (lastIndex == -1) {
            lastIndex = i;
        }
    }

    if (lastIndex != -1){
        if (lastIndex == binary.size() - 1){
            ans[lastIndex] = 1;
        } else {
            ans[binary.size()] = 1;
            ans[lastIndex] = -1;
        }
    }

    for (int i = 0; i < binary.size(); i++){
        if (ans[i] == 1 && ans[i + 1] == -1){
            ans[i] = -1;
            ans[i + 1] = 0;
        }

        if (ans[i] == 1 && ans[i + 1] == 1){
            ans[i] = -1;
            ans[i + 1] = 0;
            ans[i + 2] = 1;
        }
    }
    cout << ans.size() << endl;
    cout << ans[0];
    for (int i = 1; i < ans.size(); i++){
        cout << " " << ans[i];
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