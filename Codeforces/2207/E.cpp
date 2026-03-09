/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2026-03-08
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
    int n; cin >> n;

    vi arr(n);
    rep(i, 0, n) {
        cin >> arr[i];
    }

    if (arr[0] > n || arr[0] < n - 1) {
        cout << "NO" << endl;
        return;
    }

    rep(i, 1, n) {
        if (arr[i] > arr[i - 1]) {
            cout << "NO" << endl;
            return;
        }
    }

    stack<int> use;
    vi ans(n);

    if (arr[0] == n - 1) {
        ans[0] = n;
    } else {
        use.push(0);
    }

    rep(i, 1, n) {
        use.push(i);
        if (arr[i] < arr[i - 1]) {
            int d = arr[i - 1] - arr[i];
            if (sz(use) < d) {
                cout << "NO" << endl;
                return;
            }
            ans[use.top()] = arr[i - 1];
            use.pop();
            rep(j, 0, d - 1) {
                ans[use.top()] = arr[i - 1] - 1 - j;
                use.pop();
            }
        }
    }

    rep(i, 0, arr[n - 1]) {
        if (use.empty()) break;
        ans[use.top()] = i;
        use.pop();
    }

    cout << "YES" << endl;
    for (int b : ans) {
        cout << b << " ";
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