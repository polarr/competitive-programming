/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-05-02
 * Contest: 1968 - Codeforces Round 943
 * Problem: F
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

ll max_digit(ll x){
    ll ans = 0;
    
    while (x > 0){
        x /= 2;
        ans++;
    }

    return ans;
}

void solve(){
    int n, q;
    cin >> n >> q;
    vector<ll> arr;
    vector<ll> prefix = {0};
    ll curr = 0;
    for (int i = 0; i < n; i++){
        ll a; cin >> a;
        arr.pb(a);
        curr ^= a;
        prefix.pb(curr);
    }

    for (int i = 0; i < q; i++){
        int l, r; cin >> l >> r;

        ll target = prefix[r] ^ prefix[l - 1];
        ll last = prefix[l - 1];
        int count = 0;
        string ans = "NO";

        if (target == 0){
            if (prefix[r] == prefix[l - 1]){
                ans = "YES";
            }
        }
        else {
            for (int right = l; right <= r; right++){
                ll x = prefix[right] ^ last;
                if (x == target){
                    count++;
                    if (count >= 2){
                        ans = "YES";
                        break;
                    }

                    last = prefix[right];
                    if (prefix[r] != last){
                        break;
                    }
                }
            }
        }

        cout << ans << endl;
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