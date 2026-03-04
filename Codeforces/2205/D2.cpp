/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2026-03-03
 * Contest: 
 * Problem: D
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
    int n; cin >> n;

    vi arr(n);
    rep(i, 0, n) cin >> arr[i];

    vi l(n, 1), r(n, 1);

    stack<pii> s;
    s.push({arr[0], 0});
    rep(i, 1, n) {
        while (!s.empty() && s.top().first < arr[i]) {
            s.pop();
        }

        if (!s.empty()) {
            l[i] = l[s.top().second] + 1;
        }

        s.push({arr[i], i});
    }

    s = {};
    s.push({arr[n - 1], n - 1});
    for (int i = n - 2; i >= 0; i--) {
        while (!s.empty() && s.top().first < arr[i]) {
            s.pop();
        }

        if (!s.empty()) {
            r[i] = r[s.top().second] + 1;
        }

        s.push({arr[i], i});
    }

    int ans = 0;
    rep(i, 0, n) {
        ans = max(ans, l[i] + r[i] - 1);
    }

    cout << n - ans << endl;
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