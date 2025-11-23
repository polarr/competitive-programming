/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-11-22
 * Contest: Codeforces 2164
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
    int n, k; cin >> n >> k;
    string s, t; cin >> s >> t;

    vi a(n), b(n);
    rep(i, 0, n) {
        a[i] = s[i] - 'a';
        b[i] = t[i] - 'a';
    }

    vector<vi> last(26);
    rep(i, 0, n) {
        last[a[i]].pb(i);
    }

    vi order(n);
    int ans = 0;
    int j = n - 1;
    for (int i = n - 1; i >= 0; i--) {
        while (j > i) {
            last[a[j]].pop_back();
            j--;
        }

        int c = b[i];
        if (last[c].empty()) {
            cout << -1 << endl;
            return;
        }

        ans = max(ans, i - last[c].back());
        order[i] = last[c].back();
        while (j > last[c].back()) {
            last[a[j]].pop_back();
            j--;
        }
    }

    if (ans > k) {
        cout << -1 << endl;
        return;
    }
    
    cout << ans << endl;
    vi arr = a;
    rep(x, 1, ans + 1) {
        rep(i, 0, n) {
            int j = min(i, order[i] + x);
            arr[j] = b[i];
        }

        string curr;
        rep(i, 0, n) {
            curr += ('a' + arr[i]);
        }

        cout << curr << endl;
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