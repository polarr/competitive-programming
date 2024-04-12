/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-04-06
 * Contest: Codeforces 1951 - Global Round 25
 * Problem: D. Buying Jewels
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll MAX = 1e18;

pair<bool, vector<ll>> possible(ll n, ll k, vector<ll> prices){
    if (k == 0){
        return make_pair(true, prices);
    }

    if (n <= 0 || n < k){
        return make_pair(false, prices);
    }

    if (k <= n/2){
        prices.pb(floor(n/k));
        return make_pair(true, prices);
    } else {
        if (n < 16){
            for (int price = 1; price <= n; price++){
                ll buy = floor(n/price);
                vector<ll> prices_copy = prices;
                prices_copy.pb(price);

                pair<bool, vector<ll>> pos = possible(n - price * buy, k - buy, prices_copy);
                if (pos.first){
                    return pos;
                }
            }

            return make_pair(false, prices);
        } else {
            for (int price = 1; price <= min((ll)3, n); price++){
                ll buy = floor(n/price);
                vector<ll> prices_copy = prices;
                prices_copy.pb(price);

                pair<bool, vector<ll>> pos = possible(n - price * buy, k - buy, prices_copy);
                if (pos.first){
                    return pos;
                }
            }

            ll l = floor(n/2) - 5;
            ll h = floor(n/2) + 2;
            for (int price = max((ll)1, l); price <= min(n, h); price++){
                ll buy = floor(n/price);
                vector<ll> prices_copy = prices;
                prices_copy.pb(price);

                pair<bool, vector<ll>> pos = possible(n - price * buy, k - buy, prices_copy);
                if (pos.first){
                    return pos;
                }
            }

            return make_pair(false, prices);
        }
    }
}

void solve(){
    ll n, k;
    cin >> n >> k;

    /**
    vector<ll> prices;
    for (int i = 0; i < 60; i++){
        ll p = floor((n + k + 1)/(k + 1));
        prices.pb(p);
        ll buy = floor(n/p);
        k -= buy;
        n -= buy * p;
        if (k == 0){
            cout << "YES" << endl;
            cout << prices.size() << endl;
            cout << prices[0];
            for (int i = 1; i < prices.size(); i++){
                cout << " " << prices[i];
            }
            cout << endl;
            return;
        }

        if (n == 0){
            cout << "NO" << endl;
            return;
        }
    }
    **/

    pair<bool, vector<ll>> pos = possible(n, k, vector<ll>{});
    vector<ll> prices = pos.second;

    if (pos.first && prices.size() < 61){
        cout << "YES" << endl;
        cout << prices.size() << endl;
        cout << prices[0];
        for (int i = 1; i < prices.size(); i++){
            cout << " " << prices[i];
        }
        cout << endl;
        return;
    }

    cout << "NO" << endl;
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