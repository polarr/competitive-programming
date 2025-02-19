/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-12-28
 * Contest: ICPC NAQ 2024
 * Problem: D
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

vector<vector<pair<int, int>>> adj;
vector<ll> totalColors;
vector<map<int, ll>> colors;
vector<int> color;
vector<ll> dp;
vector<ll> ans;

void merge(int x, int y){
    if (colors[x].size() < colors[y].size()){
        colors[x].swap(colors[y]);
        swap(dp[x], dp[y]);
    }

    for (auto [c, amount] : colors[y]){
        dp[x] -= colors[x][c] * (totalColors[c] - colors[x][c]);
        colors[x][c] += amount;
        ll now = colors[x][c] * (totalColors[c] - colors[x][c]);
        dp[x] += now;
        if (now == 0){
            colors[x].erase(c);
        }
    }
}

void dfs(int n, int parent = -1){
    colors[n][color[n]] = 1;
    dp[n] = totalColors[color[n]] - 1;

    for (auto [node, i] : adj[n]){
        if (node == parent){
            continue;
        }

        dfs(node, n);
        ans[i] = dp[node];
        merge(n, node);
    }
}

void solve(){
    int n; cin >> n;

    adj = vector<vector<pair<int, int>>>(n);
    totalColors = vector<ll>(n, 0);
    color = vector<int>(n);
    colors =vector<map<int, ll>>(n);
    dp = vector<ll>(n);
    ans = vector<ll>(n);

    for (int i = 0; i < n; i++){
        cin >> color[i];
        color[i]--;
        totalColors[color[i]]++;
    }

    for (int i = 0; i < n - 1; i++){
        int a, b; cin >> a >> b;
        --a; --b;
        adj[a].pb({b, i});
        adj[b].pb({a, i});
    }

    int root = 0;
    for (int i = 0; i < n; i++){
        if (adj[i].size() > 1){
            root = i;
            break;
        }
    }

    dfs(root);

    for (int i = 0; i < n - 1; i++){
        cout << ans[i] << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}