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
    ll n; int q; cin >> n >> q;

    vector<int> a;

    ll s = 0;

    for (int i = 0; i < n; i++){
        int x; cin >> x;
        a.pb(x);

        s += x;
    }

    vector<ll> prefix(n + 1, 0);
    vector<ll> suffix(n + 1, 0);

    for (int i = 1; i < n + 1; i++){
        prefix[i] = prefix[i - 1] + a[i - 1];
        suffix[i] = suffix[i - 1] + a[n - i];
    }

    auto shift_prefix = [&] (int shift, int index) {
        ll ans = 0;

        ans += suffix[n - shift];
        if (index < n - shift){
            ans -= suffix[n - index - shift];
        }
        else if (index > n - shift){
            ans += prefix[index - n + shift];
        }
        
        return ans;
    };

    for (int i = 0; i < q; i++){
        ll l, r; cin >> l >> r;

        --l; --r;

        int ln = l/n;
        int lm = l % n;
        int rn = r/n;
        int rm = r % n;

        cout << - shift_prefix(ln, lm) + shift_prefix(rn, rm + 1) + (ll) (rn - ln) * s << endl;
    }
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