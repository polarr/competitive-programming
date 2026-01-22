/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2026-01-21
 * Contest: 
 * Problem: E
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

int ask(int i, int j) {
    cout << "? " << i + 1 << " " << j + 1 << endl;
    int ans; cin >> ans;
    return ans;
}

void solve(){
    int n; cin >> n;

    int asc = -1, x = -1;
    for (int i = n - 2; i >= 0; i--) {
        if (asc == -1) {
            int ans = ask(i, i + 1);
            if (ans == 0) {
                asc = i;
            }
        } else {
            int ans = ask(i, i + 1);
            if (ans == 1) {
                x = i;
                break;
            }
        }
    }

    if (x == -1) {
        cout << "! -1" << endl;
        return;
    }

    int lrg = x + 1;

    for (int i = x + 2; i <= asc + 1; i++) {
        if (ask(x, i) == 0) {
            lrg = i - 1;
            break;
        }
    }

    for (int i = n - 1; i >= asc; i--) {
        if (i == asc || ask(x, i) == 0) {
            if (i == n - 1) break;
            if (ask(lrg, i + 1) == 0) {
                lrg = i + 1;
            }
            break;
        }
    }

    vi ans(x + 1);
    rep(i, 0, x) {
        ans[i] = i;
    }

    ans[x] = lrg;
    vi a;
    vi b;
    rep(i, x + 1, asc + 1) {
        if (i == lrg) {
            a.pb(x);
            continue;
        }
        a.pb(i);
    }
    reverse(all(a));
    rep(i, asc + 1, n) {
        if (i == lrg) {
            b.pb(x);
            continue;
        }
        b.pb(i);
    }

    vi s;
    int ai = 0, bi = 0;
    while (ai + bi < sz(a) + sz(b)) {
        if (ai == sz(a)) {
            s.pb(b[bi]);
            bi++;
            continue;
        }

        if (bi == sz(b)) {
            s.pb(a[ai]);
            ai++;
            continue;
        }

        int ans = ask(a[ai], b[bi]);
        if (ans == 1) {
            s.pb(a[ai]);
            ai++;
        } else {
            s.pb(b[bi]);
            bi++;
        }
    }

    rep(i, 0, sz(s)) {
        ans.pb(s[i]);
    }

    cout << "!";
    rep(i, 0, sz(ans)) {
        cout << " " << ans[i] + 1;
    }

    cout << endl;
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