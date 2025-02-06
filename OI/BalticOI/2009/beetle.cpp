/**
 * Solution by 1egend (polarity.sh)
 * Date: 2025-02-03
 * Contest: Baltic OI 2009
 * Problem: beetle
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

ll dp[301][300][300][2];
int a, b;
vi pos, neg;

ll find(ll n, int l, int r, int right){
    if (n == 0){
        return 0;
    }

    if (right != 2 && dp[n][l][r][right] != 0){
        return dp[n][l][r][right];
    }

    ll mn = LLONG_MAX;

    int p = 0;
    if (right == 1){
        p = pos[r - 1];
    }
    if (right == 0){
        p = -neg[l - 1];
    }

    if (r < b){
        mn = min(mn, (ll)(pos[r] - p) * n + find(n - 1, l, r + 1, 1));
    }

    if (l < a){
        mn = min(mn, (ll)(p + neg[l]) * n + find(n - 1, l + 1, r, 0));
    }

    if (right != 2){
        dp[n][l][r][right] = mn;
    }

    return mn;
}

void solve(){
    ll n, m; cin >> n >> m;

    ll ans = 0;
    ll add = 0;
    rep(i, 0, n){
        int x; cin >> x;
        if (x == 0){
            add += m;
        }
        else if (x > 0){
            pos.pb(x);
        } else {
            neg.pb(-x);
        }
    }

    if (add != 0){
        --n;
    }

    sort(all(pos));
    sort(all(neg));

    a = neg.size(), b = pos.size();

    rep(i, 0, n + 1){
        ans = max(ans, m * (ll)i - find(i, 0, 0, 2));
    }

    cout << add + ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}