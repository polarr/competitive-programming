/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2026-02-02
 * Contest: Codeforces 1083
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
const ll INF = 1e10;

void solve(){
    int n; cin >> n;

    using T = array<ll, 3>;

    vector<T> rect(n);
    rep(i, 0, n) {
        ll x, y, a; cin >> x >> y >> a;
        rect[i] = {x, y, a};
    }

    sort(all(rect));

    deque<T> lines;
    vl dp(n, 0);
    dp[0] = max(0LL, rect[0][0] * rect[0][1] - rect[0][2]);
    lines.push_back({INF, rect[0][0], dp[0]});
    rep(i, 1, n) {
        ll cand = rect[i][0] * rect[i][1] - rect[i][2];
        ll y = -rect[i][1];
        while (y >= lines.front()[0]) {
            lines.pop_front();
        }

        T line = lines.front();
        cand = max(cand, cand + line[1] * y + line[2]);
        dp[i] = max(dp[i - 1], cand);
        while (!lines.empty()) {
            T line = lines.back();
            lines.pop_back();
            ll crit = (line[2] - dp[i])/(rect[i][0] - line[1]);
            if (lines.empty() || crit > lines.back()[0]) {
                lines.push_back({crit, line[1], line[2]});
                break;
            }
        }

        lines.push_back({INF, rect[i][0], dp[i]});
    }

    cout << dp[n - 1] << '\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}