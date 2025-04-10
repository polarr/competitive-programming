/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-04-09
 * Contest: ICPC Practice Codeforces 105633
 * Problem: K
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

    vi times(n);
    vector<pii> dp(1 << m, {-1, -1});
    rep(i, 0, n){
        string s; cin >> s;
        int a = 0;
        int cnt = 0;
        rep(j, 0, m){
            if (s[j] == 'Y'){
                a |= (1 << j);
                cnt++;
            }
        }
        times[i] = a;
        if (dp[a].first != -1){
            continue;
        }
        dp[a] = {cnt, INT_MAX - i};
    }

    int fc = -1;

    rep(i, 0, n){
        if (times[i] == (1 << m) - 1){
            if (fc != -1){
                cout << fc + 1 << " " << i + 1 << endl;
                return;
            }
            fc = i;
        }
    }

    if (fc != -1){
        pii ans = {-1, -1};
        rep(i, 0, n){
            if (i == fc){
                continue;
            }

            ans = max(ans, dp[times[i]]);
        }

        pii idx = minmax(fc, INT_MAX - ans.second);
        cout << idx.first + 1 << " " << idx.second + 1 << endl;
        return;
    }

    for (int i = (1 << m) - 1; i >= 0; i--){
        rep(j, 0, m){
            if (i & (1 << j)){
                continue;
            }

            int msk = i | (1 << j);
            dp[i] = max(dp[i], dp[msk]);
        }
    }

    int f = (1 << m) - 1;

    array<int, 3> ans = {-1, -1, -1};

    rep(i, 0, n){
        int flip = times[i] ^ f;
        if (dp[flip].first == -1){
            continue;
        }

        int cnt = 0;
        rep(j, 0, m){
            if (flip & (1 << j)){
                cnt++;
            }
        }

        pii idx = minmax(INT_MAX - i, dp[flip].second);

        ans = max(ans, {dp[flip].first - cnt, idx.second, idx.first});
    }

    if (ans[0] == -1){
        cout << "No" << endl;
        return;
    }

    cout << INT_MAX - ans[1] + 1 << " " << INT_MAX - ans[2] + 1 << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}