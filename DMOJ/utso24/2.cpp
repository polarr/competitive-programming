/**
 * Solution by 1egend (polarity.sh)
 * Date: 2025-01-03
 * Contest: DMOJ utso24
 * Problem: 2
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    ll n, k; cin >> n >> k;

    k = min(k, 2 * n);

    vector<ll> pos, neg;
    for (ll i = 0; i < n; i++){
        ll g; cin >> g;
        if (g == 0){
            continue;
        }

        if (g < 0){
            neg.pb(-g);
            continue;
        }

        pos.pb(g);
    }

    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end());

    ll ans = 0;

    int i = pos.size(), j = neg.size();
    while ((i > 0 || j > 0) && k > 0){
        if (k == 1){
            if (i == 0){
                break;
            }

            ans += pos[i - 1];
            k--;
            i--;
            continue;
        }

        ll f = 0, s = 0;
        if (i > 0){
            f = pos[i - 1];
        }

        if (i > 1){
            s = pos[i - 2];
        }

        if (j > 0 && (neg[j - 1] >= f + s)){
            k -= 2;
            ans += neg[j - 1];
            j--;
        } else {
            ans += pos[i - 1];
            k--;
            i--;
        }
    }

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}