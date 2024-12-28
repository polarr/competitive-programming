/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-12-27
 * Contest: CSES Problemset
 * Problem: 1678
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

vector<bool> visited;
vector<bool> completed;
vector<vector<int>> adj;
stack<int> curr;
bool cycle = false;

void dfs(int n){
    if (visited[n]){
        if (!completed[n]){
            cycle = true;
            curr.push(n);
        }
        return;
    }

    visited[n] = true;
    curr.push(n);

    for (int node : adj[n]){
        dfs(node);

        if (cycle){
            return;
        }
    }

    completed[n] = true;
    curr.pop();
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

        if (cycle){
            break;
        }
    }

    if (!cycle){
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    vector<int> ans;

    int b = curr.top();
    curr.pop();

    ans.pb(b);

    while (!curr.empty()){
        int t = curr.top();
        curr.pop();

        ans.pb(t);

        if (t == b){
            break;
        }
    }

    reverse(ans.begin(), ans.end());

    cout << ans.size() << endl;

    for (int i = 0; i < ans.size(); i++){
        cout << ans[i] + 1 << " ";
    }

    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}