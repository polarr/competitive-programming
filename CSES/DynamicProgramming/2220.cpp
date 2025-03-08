/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-03-07
 * Contest: CSES Problemset
 * Problem: 2220
**/

#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using pii = pair<int, int>;
#define pb push_back
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    ll a, b; cin >> a >> b;

    ll ans = 0;

    if (a == 0){
        ans++;
    } else {
        --a;
    }

    vector<ll> arr, brr;
    while (a != 0){
        arr.pb(a % 10);
        a /= 10;
    }

    while (b != 0){
        brr.pb(b % 10);
        b /= 10;
    }

    vl digit(19);
    digit[0] = 1;
    vl times(19);
    times[0] = 1;
    rep(i, 1, 19){
        times[i] = times[i - 1] * 9;
        digit[i] = digit[i - 1] + times[i];
    }

    function<ll(vector<ll>)> count;
    count = [&](vl trr){
        if (trr.size() == 0){
            return 1LL;
        }

        ll ans = digit[trr.size() - 1];
        int past = 10;
        bool good = true;
        for (int i = trr.size() - 1; i >= 0; i--){
            ll can = trr[i];
            if (past < trr[i]){
                can--;
            }

            if (i == trr.size() - 1){
                can--;
            }

            can = max(0LL, can);

            ans += can * times[i];

            if (trr[i] == past){
                good = false;
                break;
            }

            past = trr[i];
        }

        if (good){
            ans++;
        }

        return ans;
    };
    
    ans += count(brr);
    ans -= count(arr);

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}