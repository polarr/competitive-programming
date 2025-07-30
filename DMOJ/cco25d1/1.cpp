/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-06-05
 * Contest: CCO 2025 Day 1
 * Problem: 1
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
    int n; ll m;
    cin >> n >> m;

    using T = pair<ll, ll>;
    vector<T> a(n);
    rep(i, 0, n) {
        cin >> a[i].second >> a[i].first;
    }

    sort(all(a));

    vector<vl> b;
    vl v;
    ll last = 1;
    ll curr = -1;
    int j = -1;
    rep(i, 0, n){
        if (a[i].first != curr){
            if (j != -1) reverse(all(b[j]));
            v.pb(a[i].first/last);
            last = a[i].first;
            curr = a[i].first;
            b.pb({});
            j++;
        }

        b[j].pb(a[i].second);
    }

    priority_queue<ll> pq;

    ll ans = 0;
    int nn = v.size();
    rep(i, 0, nn){
        m /= v[i];

        ll take = m;
        if (i != nn - 1){
            take %= v[i + 1];
        }

        for (ll val : b[i]){
            pq.push(val);
        }

        while (take > 0 && !pq.empty()){
            ans += pq.top();
            pq.pop();
            take--;
        }

        if (i == nn - 1) continue;
        ll nx = v[i + 1];

        ll k = 0;
        ll curr = 0;
        priority_queue<ll> npq;
        while (!pq.empty()){
            curr += pq.top();
            k++;
            pq.pop();
            if (pq.empty() || k == nx){
                npq.push(curr);
                curr = 0;
                k = 0;
            }
        }

        pq = npq;
    }

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
