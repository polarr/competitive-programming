/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2026-03-03
 * Contest: 
 * Problem: C
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

const int MAX_N = 1e6 + 1;
const ll MOD = 1e9 + 7;

bool compare(vi a, vi b) {
    rep(i, 0, min(sz(a), sz(b))) {
        if (a[i] < b[i]) {
            return 0;
        } else if (a[i] > b[i]) {
            return 1;
        }
    }

    if (sz(a) < sz(b)) {
        return 0;
    }

    return 1;
}

vector<bool> occupied(MAX_N, false);

void solve(){
    int n; cin >> n;

    vector<vi> blogs(n);
    rep(i, 0, n) {
        int m; cin >> m;

        vi cand;
        rep(j, 0, m) {
            int x; cin >> x;
            cand.pb(x);
        }

        reverse(all(cand));
        map<int, bool> has;

        rep(j, 0, m) {
            int x = cand[j];
            if (!has[x]) {
                blogs[i].pb(x);
                has[x] = true;
            }
        }
    }

    vi ans;
    vi idx;
    rep(i, 0, n) {
        idx.pb(i);
    }

    while (sz(idx) > 0) {
        int j = 0;

        rep(ii, 1, sz(idx)) {
            int i = idx[ii];
            if (compare(blogs[idx[j]], blogs[i])) {
                j = ii;
            }
        }

        int k = idx[j];

        for (int x : blogs[k]) {
            ans.pb(x);
            occupied[x] = true;
        }

        idx.erase(idx.begin() + j);

        for (int i : idx) {
            vi nblog;
            rep(j, 0, sz(blogs[i])) {
                int x = blogs[i][j];
                if (!occupied[x]) {
                    nblog.pb(x);
                }
            }

            blogs[i] = nblog;
        }
    }

    for (int a : ans) {
        occupied[a] = false;
        cout << a << " ";
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