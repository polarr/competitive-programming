/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-04-28
 * Contest: DMOJ Spring Coding Bowl 2024
 * Problem: 3
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

ll diff(ll xx){
    vector<ll> digit;

    ll x = xx;
    while (x > 0){
        digit.pb(x % 10);
        x /= 10;
    }

    reverse(digit.begin(), digit.end());

    ll ans = -xx;
    for (ll i = 0; i < digit.size(); i++){
        ans += digit[i] * (ll)pow(10, i);
    }

    return ans;
}

void solve(){
    ll n, k; cin >> n >> k;

    vector<ll> good;
    vector<ll> bad;

    ll meal = 0;
    for (ll i = 0; i < n; i++){
        ll price; cin >> price;

        meal += price;
        ll d = diff(price); 
        if (d < 0){
            bad.pb(-d);
        } else {
            good.pb(d);
        }
    }

    sort(good.begin(), good.end(), greater<ll>());
    sort(bad.begin(), bad.end(), greater<ll>());

    ll mx = meal, mn = meal;
    for (ll i = 0; i < k; i++){
        if (i < good.size()){
            mx += good[i];
        }

        if (i < bad.size()){
            mn -= bad[i];
        }
    }

    ll extrag = max(0LL, k - (ll)good.size());
    ll extrab = max(0LL, k - (ll)bad.size());

    ll mg = LLONG_MAX; 
    ll mb = LLONG_MAX;
    if (good.size() > 0){
        mg = good[good.size() - 1];
    }

    if (bad.size() > 0){
        mb = bad[bad.size() - 1];
    }

    ll m = min(mg, mb);

    if (extrag % 2 == 1){
        mx -= m;
    }

    if (extrab % 2 == 1){
        mn += m;
    }

    cout << mn << " " << mx << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}