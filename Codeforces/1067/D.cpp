/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-11-29
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
    string s, t; cin >> s >> t;
    vector<pii> ans1, ans2;
    vi a(n), b(n);
    rep(i, 0, n) {
        a[i] = s[i] - '0';
        b[i] = t[i] - '0';
    }

    auto process = [&] (vi &a, vector<pii> &ans) {
        int c = -1;
        rep(i, 0, n - 1) {
            if (a[i] == a[i + 1]) {
                c = i;
                break;
            }
        }

        if (c == -1) {
            ans.pb({0, 2});
            rep(i, 0, 3) {
                a[i] = 1 - a[i];
            }
            c = 2;
        }

        int curr = a[c];

        rep(i, c + 2, n) {
            if (a[i] != curr) {
                ans.pb({c, i - 1});
                curr = 1 - curr;
            }
        }

        for (int i = c - 1; i >= 0; i--) {
            if (a[i] != curr) {
                ans.pb({i + 1, n - 1});
                curr = 1 - curr;
            }
        }

        if (curr != 0) {
            ans.pb({0, n - 1});
        }
    };

    process(a, ans1);
    process(b, ans2);
    reverse(all(ans2));
    cout << sz(ans1) + sz(ans2) << endl;
    rep(i, 0, sz(ans1)) {
        cout << ans1[i].first + 1 << " " << ans1[i].second + 1 << endl;
    }
    rep(i, 0, sz(ans2)) {
        cout << ans2[i].first + 1 << " " << ans2[i].second + 1 << endl;
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