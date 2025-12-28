/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-12-27
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
    int n, m; cin >> n >> m;

    vl arr(n);
    vector<pii> labels(n);
    rep(i, 0, n) {
        int x; cin >> x;
        labels[i] = {x, i};
    }

    if (m > n/2) {
        cout << -1 << endl;
        return;
    }

    sort(all(labels));
    rep(i, 0, n) {
        arr[i] = labels[i].first;
    }

    vector<pii> ans;

    if (m == 0) {
        ll big = arr[n - 1];
        ll big2 = arr[n - 2];

        int i = 0;

        while (i < n - 1 && arr[n - 1] > arr[n - 2]) {
            ans.pb({i, n - 1});
            arr[n - 1] -= arr[i];
            i++;
        }

        if (i == n - 1) {
            cout << -1 << endl;
            return;
        }

        while (i < n - 1) {
            ans.pb({i + 1, i});
            i++;
        }
    } else {
        int cnt = n/2 - m;
        for (int i = 0; i < n; i += 2) {
            if (i == n - 1) {
                ans.pb({i, i - 1});
                break;
            }

            if (i != 0 && cnt > 0) {
                ans.pb({i, i - 1});
                cnt--;
            }

            ans.pb({i + 1, i});
        }
    }

    cout << sz(ans) << endl;

    rep(i, 0, sz(ans)) {
        pii p = ans[i];
        cout << labels[p.first].second + 1 << " " << labels[p.second].second + 1 << endl;
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