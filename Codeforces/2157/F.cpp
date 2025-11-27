/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-11-26
 * Contest: 
 * Problem: F
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
    vector<pii> ans;

    function<vi(vi, int)> partition;
    partition = [&](vi arr, int block) -> vi {
        vi breakpoints;
        vi remain;
        for (int i = 0; i * block < sz(arr) - 1; i++) {
            breakpoints.pb(i * block);
            if (i > 0) remain.pb(arr[i * block]);
        }

        remain.pb(arr.back());

        rep(i, 0, block) {
            for (int j = sz(breakpoints) - 1; j >= 0; j--) {
                int s = breakpoints[j];
                if (s + i >= sz(arr) - 1) {
                    continue;
                }
                ans.pb({arr[s + i], arr[s + i + 1] - arr[s + i]});
            }
        }

        rep(i, breakpoints.back() + block, sz(arr) - 1) {
            ans.pb({arr[i], arr[i + 1] - arr[i]});
        }

        return remain;
    };

    vi arr(n);
    rep(i, 0, n) {
        arr[i] = i + 1;
    }

    int x = cbrt(n);
    arr = partition(arr, x);
    n = sz(arr);
    x = sqrt(n);
    arr = partition(arr, x);
    n = sz(arr);

    rep(i, 0, n - 1) {
        ans.pb({arr[i], arr[i + 1] - arr[i]});
    }

    cout << sz(ans) << endl;
    for (pii a : ans) {
        cout << a.first << " " << a.second << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}