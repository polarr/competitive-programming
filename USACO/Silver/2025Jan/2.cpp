/**
 * Solution by 1egend (polarity.sh)
 * Date: 2025-01-24
 * Contest: USACO 2025 January Silver
 * Problem: 2
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
    int n, m; cin >> n >> m;

    vl a(n);
    vector<array<ll, 3>> triggers;
    ll ta = 0, tb = 0;

    ll mid = m/2;

    ll curr = 0;

    for (int i = 0; i < n; i++){
        cin >> a[i];
        a[i] %= m;
    }

    sort(all(a));

    vector<int> state(n, 0);

    auto classify = [&](ll x){
        if (x < 0){
            x += m;
        }

        if (x <= mid){
            return 0;
        }

        return 1;
    };

    auto contrib = [&](ll x){
        if (x < 0){
            x += m;
        }

        if (x <= mid){
            return x;
        }

        return m - x;
    };

    int s = a[0];

    for (int i = 0; i < n; i++){
        a[i] -= s;

        if (a[i] <= mid){
            ta++;
            curr += a[i];
            state[i] = 0;
            triggers.pb({a[i] + 1, a[i] + m - mid, i});
            triggers.pb({a[i] + m - mid, INT_MAX, i});
        } else {
            tb++;
            curr += m - a[i];
            state[i] = 1;
            triggers.pb({a[i] - mid, a[i] + 1, i});
            triggers.pb({a[i] + 1, INT_MAX, i});
        }
    }

    sort(all(triggers));

    ll ans = curr;

    int j = 0;

    for (int i = 1; i < n; i++){
        ll x = a[i];
        ll prev = a[i - 1];
        ll delta = x - prev;

        if (delta == 0){
            continue;
        }

        // try setting a[i] = 0, so choose x = a[i]

        ll adjust = 0;

        while(j < 2 * n && triggers[j][0] <= x){
            ll nx = triggers[j][1];
            int ii = triggers[j][2];

            // cout << "Triggered: " << a[ii] << " " << triggers[j][0] << "<=" << x << endl;

            if (nx <= x){
                j++;
                continue;
            }

            curr += contrib(a[ii] - x) - contrib(a[ii] - prev);

            bool realState = classify(a[ii] - x);

            if (state[ii] == 0){
                ta--;
            } else {
                tb--;
            }

            if (realState == 0){
                ta++;
                adjust++;
            } else {
                tb++;
                adjust--;
            }

            state[ii] = realState;
            j++;
        }

        curr += delta * (tb - ta + adjust);

        // cout << adjust << endl;

        ans = min(ans, curr);
    }

    cout << ans << endl;
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