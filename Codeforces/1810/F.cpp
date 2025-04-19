/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-04-18
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

    if (n % 2 == 0){
        cout << -1 << endl;
        return;
    }

    vi a;
    int x = n;
    while (x != 0){
        a.pb(x % 2);
        x /= 2;
    }

    vi ans;

    reverse(all(a));
    rep(i, 0, a.size() - 1){
        int x = a[i];
        if (x == 1){
            ans.pb(2);
        } else {
            ans.pb(1);
        }
    }

    cout << ans.size() << endl;
    for(int a : ans){
        cout << a  << " ";
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