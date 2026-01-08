/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2026-01-07
 * Contest: CSES Problemset
 * Problem: 1161
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
    ll x; int n; cin >> x >> n;

    priority_queue<ll, vl, greater<ll>> sticks;
    rep(i, 0, n) {
        ll stick; cin >> stick;
        sticks.push(stick);
    }

    ll ans = 0;
    while (sz(sticks) > 1) {
        ll a = sticks.top();
        sticks.pop();
        ll b = sticks.top();
        sticks.pop();
        ans += a + b;
        sticks.push(a + b);
    }

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}