/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-10-23
 * Contest: BOJ
 * Problem: 9726
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

const ll MAX_N = 1e17;
const ll lg = log2(MAX_N) + 1;
const ll MOD = 1e9 + 7;

vector<vi> pow2(lg), npow2(lg);

void solve(){
    ll n; cin >> n;

    vi ans = {0};

    auto add = [&](vi a, vi b) -> vi {
        if (sz(a) > sz(b)){
            swap(a, b);
        }

        int carry = 0;
        int idx = 0;

        while (idx < sz(a) || carry != 0){
            if (idx >= sz(a)){
                a.pb(0);
            }

            if (idx >= sz(b)){
                b.pb(0);
            }

            int curr = a[idx] + carry + b[idx];
            if (curr == -1){
                b[idx] = 1;
                carry = 1;
            } else if (curr == 2){
                b[idx] = 0;
                carry = -1;
            } else if (curr == 3){
                b[idx] = 1;
                carry = -1;
            } else {
                b[idx] = curr;
                carry = 0;
            }

            idx++;
        }

        return b;
    };

    bool neg = n < 0;
    if (neg){
        n = -n;
    }

    int pw = 0;
    while (n > 0){
        if (n % 2 == 1){
            ans = add(ans, neg ? npow2[pw] : pow2[pw]);
        }

        n /= 2;
        pw++;
    }

    reverse(all(ans));
    rep(i, 0, sz(ans)){
        cout << ans[i];
    }

    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    rep(i, 0, lg){
        rep(j, 0, i){
            pow2[i].pb(0);
        }
        pow2[i].pb(1);

        if (i % 2 == 1){
            pow2[i].pb(1);
        }
    }

    rep(i, 0, lg){
        rep(j, 0, i){
            npow2[i].pb(0);
        }
        npow2[i].pb(1);

        if (i % 2 == 0){
            npow2[i].pb(1);
        }
    }

    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; ++t){
        cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}