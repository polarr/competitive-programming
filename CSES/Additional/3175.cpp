/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-12-10
 * Contest: 
 * Problem: 3175
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
    int k = n/5;
    int r = n % 5;

    if (n == 2 || n == 3) {
        cout << "NO SOLUTION" << endl;
        return;
    }

    vi ans;
    vi cons = {1, 3, 5, 2, 4};
    rep(i, 0, k) {
        rep(j, 0, 5) {
            ans.pb(5 * i + cons[j]);
        }
    }

    rep(j, 0, 5) {
        cons[j] = 5 * k + j + 1;
    }

    if (r == 1) {
        ans.pb(cons[0]);
    } else if (r == 2) {
        int el = ans.back();
        ans.pop_back();
        ans.pb(cons[0]);
        ans.pb(el);
        ans.pb(cons[1]);
    } else if (r == 3) {
        int el = ans.back();
        ans.pop_back();
        ans.pb(cons[0]);
        ans.pb(cons[2]);
        ans.pb(el);
        ans.pb(cons[1]);
    } else if (r == 4) {
        ans.pb(cons[1]);
        ans.pb(cons[3]);
        ans.pb(cons[0]);
        ans.pb(cons[2]);
    }

    rep(i, 0, sz(ans)) {
        cout << ans[i] << " ";
    }

    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    solve();
    return 0;
}