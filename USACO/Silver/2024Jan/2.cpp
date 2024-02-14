/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-01-29
 * Contest: USACO 2024 Jan Contest
 * Problem: Silver P2. Potion Farming
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

vector<int> depth;
vector<vector<int>> leafs;
vector<vector<int>> adj;

vector<int> dfs(int v, int d){
    if (depth[v] != 0){
        return {};
    }

    depth[v] = d;

    if (adj[v].size() == 1 && d > 1){
        leafs[v] = {v};
        return {v};
    }

    for (int i : adj[v]){
        for (int j : dfs(i, d + 1)){
            leafs[v].pb(j);
        }
    }

    return leafs[v];
}

void solve(){
    int n;
    cin >> n;

    depth = vector<int>(n + 1, 0);
    adj = vector<vector<int>>(n + 1);
    leafs = vector<vector<int>>(n + 1);
    unordered_set<int> taken;
    vector<int> pot;
    for (int i = 0; i < n; i++){
        int p;
        cin >> p;
        pot.pb(p);
    }

    for (int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    dfs(1, 1);

    vector<pair<int, int>> potions;
    for (int i = 0; i < leafs[1].size(); i++){
        int p = pot[i];
        potions.pb(make_pair(depth[p], p));
    }

    sort(potions.begin(), potions.end(), greater{});
    int ans = 0;
    for (int i = 0; i < potions.size(); i++){
        int potion = potions[i].second;
        for (int j : leafs[potion]){
            if (taken.count(j) == 0){
                taken.insert(j);
                ans++;
                break;
            }
        }
    }

    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}