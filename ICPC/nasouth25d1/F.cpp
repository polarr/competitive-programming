#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using pii = pair<int, int>;
#define rep(i, a, b) for(int i = (a); i < (b); ++i)

const ll INF = 1e17;

void solve(){
    int n, t, k; cin >> n >> t >> k;
    int mx = t - k;

    vector<pii> meetings(n + 1);
    rep(i, 0, n){
        cin >> meetings[i + 1].second;
        cin >> meetings[i + 1].first;
    }

    meetings[0] = {0, 0};

    sort(meetings.begin(), meetings.end());

    vector<vl> dp(n + 1, vl(n + 1, INF));
    dp[0][0] = 0;

    rep(i, 1, n + 1){
        dp[i][0] = 0;
        int s = meetings[i].second;
        int e = meetings[i].first;

        ll len = e - s;
        int mx = 0;

        rep(j, 0, i){
            if (meetings[j].first <= s){
                mx = j;
            } else {
                break;
            }
        }

        rep(j, 1, n + 1){
            if (j > i + 1){
                break;
            }

            dp[i][j] = dp[i - 1][j];
            dp[i][j] = min(dp[i][j], len + dp[mx][j - 1]);
        }
    }

    ll ans = 0;
    for (int j = n; j >= 0; j--){
        if (dp[n][j] <= mx){
            ans = j;
            break;
        }
    }

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}