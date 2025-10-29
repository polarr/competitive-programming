/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-10-28
 * Contest: Codeforces 321
 * Problem: C
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

struct CentroidDecomposition {
	vector<vector<int>> adj;
    vector<bool> is_removed;
    vector<int> subtree_size;

    /** DFS to calculate the size of the subtree rooted at `node` */
    int get_subtree_size(int node, int parent = -1) {
        subtree_size[node] = 1;
        for (int child : adj[node]) {
            if (child == parent || is_removed[child]) { continue; }
            subtree_size[node] += get_subtree_size(child, node);
        }
        return subtree_size[node];
    }

    /**
     * Returns a centroid (a tree may have two centroids) of the subtree
     * containing node `node` after node removals
     * @param node current node
     * @param tree_size size of current subtree after node removals
     * @param parent parent of u
     * @return first centroid found
     */
    int get_centroid(int node, int tree_size, int parent = -1) {
        for (int child : adj[node]) {
            if (child == parent || is_removed[child]) { continue; }
            if (subtree_size[child] * 2 > tree_size) {
                return get_centroid(child, tree_size, node);
            }
        }
        return node;
    }

    /** Build up the centroid decomposition recursively */
    void build_centroid_decomp(int node, int par, vector<int> &ans) {
        int centroid = get_centroid(node, get_subtree_size(node));

        ans[centroid] = par;

        is_removed[centroid] = true;

        for (int child : adj[centroid]) {
            if (is_removed[child]) { continue; }
            build_centroid_decomp(child, centroid, ans);
        }
    }

    vector<int> build(int n, vector<vi> a){
        adj = a;
        is_removed = vector<bool>(n);
        subtree_size = vector<int>(n);
        vector<int> ans(n, -1);

        build_centroid_decomp(0, -1, ans);
        return ans;
    }
};

void solve(){
    int n; cin >> n;
    vector<vi> adj(n);
    rep(i, 0, n - 1){
        int a, b; cin >> a >> b;
        --a; --b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    CentroidDecomposition centroid;
    vi par = centroid.build(n, adj);
    
    rep(i, 0, n){
        int depth = 0;
        int curr = i;
        while (par[curr] != -1){
            curr = par[curr];
            depth++;
        }

        assert(depth < 26);

         cout << (char)('A' + depth) << " ";
    }
    
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}