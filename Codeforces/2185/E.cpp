/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2026-03-06
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

void solve(){
    int n, m, k; cin >> n >> m >> k;

    vi robots(n);
    rep(i, 0, n) cin >> robots[i];

    set<int> spikes;
    rep(i, 0, m) {
        int x; cin >> x;
        spikes.insert(x);
    }

    vi die(k, 0);

    pii ran = {0, 0};
    int curr = 0;
    vector<pii> r(k);
    rep(i, 0, k) {
        char ins; cin >> ins;
        if (ins == 'L') {
            curr--;
        } else {
            curr++;
        }

        ran.first = min(ran.first, curr);
        ran.second = max(ran.second, curr);
        r[i] = ran;
    }

    rep(i, 0, n) {
        int pos = robots[i];
        auto j = spikes.lower_bound(pos);
        int pr = -1e9, nx = 2e9;
        if (j != spikes.begin()) {
            pr = *prev(j);
        }
        if (j != spikes.end()) {
            nx = *j;
        }

        int lo = 0, hi = k;
        while (lo < hi) {
            int mid = (lo + hi)/2;

            bool dead = mid == k;
            if (mid < k) {
                pii move = r[mid];
                dead = pos + move.first <= pr || pos + move.second >= nx;
            }

            if (dead) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }

        if (lo != k) {
            die[lo]++;
        }
    }

    int alive = n;
    rep(i, 0, k) {
        alive -= die[i];
        cout << alive << " ";
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