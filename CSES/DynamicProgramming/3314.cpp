/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-05-16
 * Contest: CSES Problemset
 * Problem: 3314
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
    int n; cin >> n;
    vi h(n);
    rep(i, 0, n){
        cin >> h[i];
    }

    vector<vi> adj(n);

    stack<pii> nle;

    for (int i = n - 1; i >= 0; i--){
        while(!nle.empty() && nle.top().first <= h[i]){
            nle.pop();
        }

        if (!nle.empty()){
            adj[i].pb(nle.top().second);
        }

        nle.push({h[i], i});
    }

    nle = {};
    rep(i, 0, n){
        while(!nle.empty() && nle.top().first <= h[i]){
            nle.pop();
        }

        if (!nle.empty()){
            adj[i].pb(nle.top().second);
        }
        nle.push({h[i], i});
    }

    vi order = toposort(n, adj);
    int ans = 1;
    vi dp(n, 1);
    for (int j = n - 1; j >= 0; j--){
        int i = order[j];
        for (int node : adj[i]){
            dp[i] = max(dp[i], 1 + dp[node]);
        }

        ans = max(ans, dp[i]);
    }

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}