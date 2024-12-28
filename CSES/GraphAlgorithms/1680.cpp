/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-12-27
 * Contest: CSES Problemset
 * Problem: 1680
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

vector<int> ans;
vector<bool> visited;
vector<bool> completed;
vector<vector<int>> adj;
bool cycle = false;

void dfs(int n){
    if (visited[n]){
        if (!completed[n]){
            cycle = true;
        }
        return;
    }

    visited[n] = true;

    for (int node : adj[n]){
        dfs(node);
    }

    completed[n] = true;
    ans.pb(n);
}

void solve(){
    int n, m; cin >> n >> m;

    visited = vector<bool>(n, false);
    adj = vector<vector<int>>(n);
    completed = visited;
    
    for (int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        --a; --b;

        adj[a].pb(b);
    }

    for (int i = 0; i < n; i++){
        if (!visited[i]){
            dfs(i);
        }
    }

    reverse(ans.begin(), ans.end());

    vector<int> maxprev(n);
    vector<int> dp(n, 0);

    maxprev[0] = -1;
    dp[0] = 1;

    for (int ii = 0; ii < n; ii++){
        int i = ans[ii];
        if (dp[i] == 0){
            continue;
        }

        for (int j = 0; j < adj[i].size(); j++){
            int node = adj[i][j];
            if (dp[node] < dp[i] + 1){
                dp[node] = dp[i] + 1;
                maxprev[node] = i;
            }
        }
    }

    if (dp[n - 1] == 0){
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    cout << dp[n - 1] << endl;

    vector<int> a;
    
    int k = n - 1;
    while(k != -1){
        a.pb(k);

        k = maxprev[k];
    }

    reverse(a.begin(), a.end());
    for (int i = 0; i < a.size(); i++){
        cout << a[i] + 1 << " ";
    }

    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}