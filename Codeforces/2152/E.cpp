/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-10-03
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

vi query(vi &a){
    cout << "? " << sz(a);
    for (int el : a){
        cout << " " << el + 1;
    }
    cout << endl;
    int n; cin >> n;
    vi ans(n);
    rep(i, 0, n) {
        int x; cin >> x;
        ans[i] = x - 1;
    }
    return ans;
}

void solve(){
    int n; cin >> n;
    int k = n * n + 1;
    vi iter(k, n);
    rep(i, 0, n){
        vi ask;
        rep(j, 0, k){
            if (iter[j] == n){
                ask.pb(j);
            }
        }

        vi res = query(ask);
        if (sz(res) > n){
            cout << "!";
            rep(j, 0, n + 1){
                cout << " " << res[j] + 1;
            }
            cout << endl;
            return;
        }

        for (int el : res){
            iter[el] = i;
        }
    }

    int curr;
    rep(i, 0, k){
        if (iter[i] == n){
            curr = i;
            break;
        }
    }

    vi ans = {curr};
    for (int i = curr - 1; i >= 0; i--){
        if (iter[i] == iter[curr] - 1){
            ans.pb(i);
            curr = i;
        }
    }

    reverse(all(ans));
    assert(sz(ans) == n + 1);
    cout << "!";
    rep(i, 0, n + 1){
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