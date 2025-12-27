/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-12-26
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

/** 
 * ALGORITHM: Topological Sort
 * PURPOSE: Sorts a DAG's vertices such that each directed edge points forward
 * CONSTRAINT: Graph must be a DAG
 * TIME: O(V)
*/
vector<int> toposort(int n, vector<vector<int>> &adj){
    vector<int> degree(n, 0);
    queue<int> q; // use pq for lexicographical sorting
    for (int i = 0; i < n; i++){
        for (int j : adj[i]){
            degree[j]++;
        }
    }

    for (int i = 0; i < n; i++){
        if (degree[i] == 0){
            q.push(i);
        }
    }

    vector<int> ans;

    while(!q.empty()){
        int i = q.front();
        ans.pb(i);
        q.pop();

        for (int j : adj[i]){
            if (degree[j] == 0){
                continue;
            }

            degree[j]--;
            if (degree[j] == 0){
                q.push(j);
            }
        }
    }

    return ans;
}

void solve(){
    int n, m; cin >> n >> m;
    ll k; cin >> k;

    vector<vi> adj(n);
    vector<vi> radj(n);

    vl time(n);

    rep(i, 0, n) {
        cin >> time[i];
    }

    rep(i, 0, m) {
        int a, b; cin >> a >> b;
        --a; --b;
        adj[a].pb(b);
        radj[b].pb(a);
    }

    vi order = toposort(n, adj);

    vl dp(n, -1);

    rep(i, 0, n) {
        int x = order[i];
        dp[x] = time[x];

        for (int node : radj[x]) {
            ll day = dp[node] / k;

            if (time[node] <= time[x]) {
                dp[x] = max(dp[x], day * k + time[x]);
            } else {
                dp[x] = max(dp[x], (day + 1) * k + time[x]);
            }
        }
    }

    ll mxtime = *max_element(all(dp));
    // cout << mxtime << '\n';

    vector<pair<ll, ll>> dp2(n);
    rep(i, 0, n) {
        int x = order[n - 1 - i];
        // dp2[x].first = dp[x];

        ll mx = mxtime;
        for (int node : adj[x]) {
            mx = min(mx, dp2[node].first);
        }

        ll day = mx / k;
        ll hour = mx % k;
        if (hour >= time[x]) {
            dp2[x].first = day * k + time[x];
        } else {
            dp2[x].first = (day - 1) * k + time[x];
        }

        dp2[x].second = dp2[x].first + k;

        for (int node : adj[x]) {
            if (dp2[x].first + k > dp2[node].first) {
                dp2[x].second = max(dp2[x].second, dp2[node].second);
            }
        }
    }

    ll mntime = 1e18;
    rep(i, 0, n) {
        mntime = min(mntime, dp2[i].first);
    }

    ll orgmx = mxtime;
    ll ans = mxtime - mntime;
    sort(all(dp2));
    rep(i, 0, n - 1) {
        if (dp2[i].second >= orgmx + k) break;
        mntime = dp2[i + 1].first;
        mxtime = max(mxtime, dp2[i].second);

        ans = min(ans, mxtime - mntime);
    }

    cout << ans << '\n';
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