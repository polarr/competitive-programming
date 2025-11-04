/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-11-03
 * Contest: Codeforces 2168
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

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void first(){
    int x; cin >> x;
    x--;
    int xr = 0;
    int cnt = 0;
    vi ans;
    rep(i, 0, 15){
        if (x & (1 << i)){
            ans.pb(i + 1);
            xr ^= (i + 1);
            cnt++;
        }
    }

    rep(i, 0, 4){
        if (xr & (1 << i)){
            ans.pb(i + 16);
        }
    }

    if (cnt % 2 == 1){
        ans.pb(20);
    }

    cout << sz(ans) << endl;
    rep(i, 0, sz(ans)){
        cout << ans[i] << " ";
    }
    cout << endl;
}

void second(){
    int n; cin >> n;
    vi has(20, 0);
    rep(i, 0, n){
        int a; cin >> a;
        --a;
        has[a] = 1;
    }

    int target = 0;
    rep(i, 15, 19){
        if (has[i]){
            target += (1 << (i - 15));
        }
    }

    int xr = 0;
    int cnt = 0;
    int ans = 0;
    rep(i, 0, 15){
        if (has[i] != 0){
            ans += (1 << i);
            xr ^= (i + 1);
            cnt++;
        }
    }

    if (xr == target){
        cout << ans + 1 << endl;
        return;
    }

    if ((cnt % 2) == has[19]){
        cout << ans + 1 << endl;
        return;
    }

    // something changed
    int change = xr ^ target;
    change--;
    ans ^= (1 << change);
    cout << ans + 1 << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string cs; cin >> cs;
    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; ++t){
        // cout << "Case #" << t << ": ";
        if (cs[0] == 'f'){
            first();
        } else {
            second();
        }
    }
    return 0;
}