/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-09-24
 * Contest: 
 * Problem: H
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

vector<vi> adj;
vector<map<int, ll>> colors;
vi color;
vl mx;
vl dp;
vl ans;

void merge(int x, int y){
    if (colors[x].size() < colors[y].size()){
        colors[x].swap(colors[y]);
        swap(dp[x], dp[y]);
        swap(mx[x], mx[y]);
    }

    for (auto [c, amount] : colors[y]){
        colors[x][c] += amount;
        if (colors[x][c] > mx[x]){
            dp[x] = c;
            mx[x] = colors[x][c];
        } else if (colors[x][c] == mx[x]){
            dp[x] += c;
        }
    }
}

void dfs(int n, int parent = -1){
    colors[n][color[n]] = 1;
    mx[n] = 1;
    dp[n] = color[n];

    for (int node : adj[n]){
        if (node == parent){
            continue;
        }

        dfs(node, n);
        merge(n, node);
    }

    ans[n] = dp[n];
}

void solve(){
    int n; cin >> n;

    colors = vector<map<int, ll>>(n);
    color = vi(n);
    mx = vl(n, -1);
    dp = vl(n);
    ans = vl(n);
    adj = vector<vi>(n);
    rep(i, 0, n){
        cin >> color[i];
    }
    rep(i, 0, n - 1){
        int a, b; cin >> a >> b;
        --a; --b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    dfs(0, -1);

    rep(i, 0, n){
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}