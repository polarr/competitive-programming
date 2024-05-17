/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-05-10
 * Contest: Olympiads School CCO Training Contest 6
 * Problem: 3
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

vector<vector<int>> children;
vector<int> dist;
vector<vector<int>> lca;
vector<vector<int>> ancestor;
vector<vector<bool>> is_ancestor;

void tree_dfs(int n, int d, vector<int> an, vector<bool> is_an){
    dist[n] = d;
    an.pb(n);
    is_an[n] = true;
    ancestor[n] = an;
    is_ancestor[n] = is_an;
    for (int child: children[n]){
        tree_dfs(child, d + 1, an, is_an);
    }
}

void solve(){
    int n, k; cin >> n >> k;

    children = vector<vector<int>>(n + 1);
    dist = vector<int>(n + 1, 0);
    lca = vector<vector<int>>(n + 1, vector<int>(n + 1, 1));
    ancestor = vector<vector<int>>(n + 1);
    is_ancestor = vector<vector<bool>>(n + 1, vector<bool>(n + 1, false));

    for (int i = 2; i <= n; i++){
        int p; cin >> p;
        children[p].pb(i);
    }

    tree_dfs(1, 0, vector<int>{}, vector<bool>(n + 1, false));
    for (int i = 1; i < n + 1; i++){
        for (int j = i; j < n + 1; j++){
            if (i == j){
                lca[i][i] = i;
                continue;
            }
            int k = 0;
            int max_k = min(ancestor[i].size(), ancestor[j].size());
            while(k < max_k && ancestor[i][k] == ancestor[j][k]){
                k++;
            }

            lca[i][j] = ancestor[i][k - 1];
            lca[j][i] = lca[i][j];
        }
    }

    vector<vector<int>> paths;

    for (int i = 0; i < k; i++){
        int a, b; cin >> a >> b;
        if (is_ancestor[a][b]){
            swap(a, b);
        }
        paths.pb(vector<int>{lca[a][b], a, b});
    }

    int ans = 0;

    for (int i = 0; i < k - 1; i++){
        for (int j = i + 1; j < k; j++){
            vector<int> apath = paths[i];
            vector<int> bpath = paths[j];
            if (is_ancestor[apath[0]][bpath[0]]){
                swap(apath, bpath);
            }

            if (!is_ancestor[bpath[0]][apath[0]]){
                continue;
            }

            if (apath[0] == bpath[0]){
                ans = max(ans, dist[lca[apath[1]][bpath[1]]] + dist[lca[apath[2]][bpath[2]]] - 2 * dist[bpath[0]]);
                ans = max(ans, dist[lca[apath[1]][bpath[2]]] + dist[lca[apath[2]][bpath[1]]] - 2 * dist[bpath[0]]);
                // cout << "same " << apath[0] << " " << bpath[0] << " " << ans << endl;
                continue;
            }

            if (lca[apath[2]][bpath[2]] == bpath[0]){
                swap(bpath[1], bpath[2]);
            }

            ans = max(ans, dist[lca[apath[2]][bpath[2]]] - dist[bpath[0]]);

            if (lca[apath[1]][bpath[2]] == bpath[0]){
                swap(bpath[1], bpath[2]);
            }

            ans = max(ans, dist[lca[apath[1]][bpath[2]]] - dist[bpath[0]]);
            // cout << "d " << apath[0] << " " << bpath[0] << " " << ans << endl;
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