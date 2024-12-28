/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-12-28
 * Contest: Codeforces 2053
 * Problem: E
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

vector<vector<int>> adj;
vector<int> type;
ll type0 = 0, type1 = 0, type2 = 0;
vector<bool> visited;
vector<array<int, 3>> subtr;

ll ans2 = 0;

void dfs_type(int n){
    if (visited[n]){
        return;
    }

    visited[n] = true;
    if (adj[n].size() == 1){
        type[n] = 0;
    }

    for (auto node : adj[n]){
        dfs_type(node);

        if (type[n] == -1 && type[node] == 0){
            type[n] = 1;
        }
    }

    if (type[n] == -1){
        type[n] = 2;
    }
}

void dfs_subtr(int n){
    if (visited[n]){
        return;
    }

    visited[n] = true;
    if (type[n] == 0){
        subtr[n] = {1, 0, 0};
        return;
    }

    int a = 0, b = 0, c = 0;

    if (type[n] == 1){
        b++;
    }

    if (type[n] == 2){
        c++;
    }

    for (auto node : adj[n]){
        if (visited[node]){
            continue;
        }

        dfs_subtr(node);
        a += subtr[node][0];
        b += subtr[node][1];
        c += subtr[node][2];
    }

    subtr[n] = {a, b, c};
}

void dfs_ans(int n){
    if (visited[n]){
        return;
    }

    visited[n] = true;

    ll contrib = 0;

    for (auto node : adj[n]){
        ll a = subtr[node][0], b = subtr[node][1], c = subtr[node][2];

        if (visited[node]){
            // upstream
            a = type0 - subtr[n][0];
            b = type1 - subtr[n][1];
            c = type2 - subtr[n][2];
        }

        if (type[n] == 1 && type[node] != 0){
            contrib += type2 - c;
        }

        dfs_ans(node);
    }

    if (type[n] == 1){
        ans2 += contrib;
    }
}

void solve(){
    int n; cin >> n;

    type0 = 0, type1 = 0, type2 = 0;
    ans2 = 0;
    type = vector<int>(n, -1);
    visited = vector<bool>(n, false);
    adj = vector<vector<int>>(n);
    subtr = vector<array<int, 3>>(n, {-1, -1, -1});

    for (int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        --u; --v;

        adj[u].pb(v);
        adj[v].pb(u);
    }
    
    if (n == 2){
        cout << 0 << endl;
        return;
    }

    dfs_type(0);

    ll ans = 0;

    int root = 0;

    for (int i = 0; i < n; i++){
        if (type[i] == 0){
            type0++;
            continue;
        }

        root = i;

        if (type[i] == 1){
            type1++;
            continue;
        }

        type2++;
    }

    // cout << n << type0 << type1 << type2 << endl;

    // starts with aron win
    ans += type0 * (type1 + type2);

    // aron wins after nora first move
    visited = vector<bool>(n, false);
    dfs_subtr(root);

    visited = vector<bool>(n, false);
    dfs_ans(root);

    cout << ans + ans2 << endl;
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