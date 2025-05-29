    /**
     * Solution by Charles Ran (polarity.sh)
     * Date: 2025-05-28
     * Contest: Codeforces 609
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
     * DS: Disjoint Set Union 
     * PURPOSE: Dynamically updates connectedness of graph by adding edges
     * TIME: amortized O(a(N)) to query
    */
    class DSU {
        private: 
            vector<int> parents;
            vector<int> sizes;
        
        public:
            DSU(int size) : parents(size), sizes(size, 1){
                for (int i = 0; i < size; i++){
                    parents[i] = i;
                }
            }

            int find(int x){
                return (parents[x] == x ? x : (parents[x] = find(parents[x])));
            }

            bool unite(int a, int b){
                int parentA = find(a);
                int parentB = find(b);
                if (parentA == parentB){
                    return false;
                }

                if (sizes[parentA] > sizes[parentB]){
                    swap(parentA, parentB);
                }

                sizes[parentB] += sizes[parentA];
                parents[parentA] = parentB;
                return true;
            }

            bool connected(int a, int b){
                return find(a) == find(b);
            }
    };

    /** 
     * DATASTRUCTURE: Segment Tree
     * PURPOSE: Range Updates and Queries
     * TIME: O(log n) to update and query
    */
    template <class T> class SegmentTree {
    private:
        const T UNIT = {INT_MAX, INT_MAX};

        T combine(T a, T b){
            return min(a, b);
        }

        vector<T> segtree;
        int len;

    public:
        SegmentTree(int len) : len(len), segtree(len * 2, UNIT) {}

        void set(int ind, T val) {
            ind += len;
            segtree[ind] = val;
            for (; ind > 1; ind /= 2) {
                segtree[ind / 2] = combine(segtree[ind], segtree[ind ^ 1]);
            }
        }

        // [start, end)
        T query(int start, int end) {
            T ans = UNIT;
            for (start += len, end += len; start < end; start /= 2, end /= 2) {
                if (start % 2 == 1) { ans = combine(ans, segtree[start++]); }
                if (end % 2 == 1) { ans = combine(ans, segtree[--end]); }
            }
            return ans;
        }
    };

    /**
     * ALGORITHM: Lowest Common Ancestor
     * PURPOSE: Lowest common ancestor node of two nodes, also supports depth and distance of nodes
     * TIME: O(n) preprocessing, O(log N) lca query
     * REQUIRE: Segment Tree (or another RMQ structure)
     */
    class LCA {
        private: 
            /** IN SEGTREE REMEMBER TO SET UNIT = pii{INT_MAX, INT_MAX} */
            SegmentTree<pii> st;
            vi first;
            vi tour;
            vector<pii> par;
            vi d;

        public:
            LCA(int n, vector<vector<pii>> &adj) : st(2 * n - 1), par(n), first(n), tour(2 * n - 1), d(n) {
                int i = -1;
                function<void(int, int, int)> dfs;
                dfs = [&](int node, int parent, int depth){
                    tour[++i] = node;
                    first[node] = i;
                    d[node] = depth;
                    for (auto &[x, w] : adj[node]){
                        if (x != parent){
                            dfs(x, node, depth + 1);
                            par[x] = {node, w};
                            tour[++i] = node;
                        }
                    }
                };

                par[0] = {-1, 0};

                // root at 0
                dfs(0, -1, 0);

                rep(i, 0, 2 * n - 1){
                    st.set(i, {d[tour[i]], tour[i]});
                }
            }

            pii parent(int node){
                return par[node];
            }

            int depth(int node){
                return d[node];
            }

            int lca(int a, int b){
                pii range = minmax(first[a], first[b]);
                /** IN SPARSE TABLE REMEMBER TO USE INCLUSIVE BOUND range.second */
                return st.query(range.first, range.second + 1).second;
            }

            int dist(int a, int b){
                return d[a] + d[b] - 2 * d[lca(a, b)];
            }
    };

    void solve(){
        int n, m; cin >> n >> m;

        vector<vector<pii>> adj(n);
        vector<array<int, 4>> edges;

        rep(i, 0, m){
            int a, b, w; cin >> a >> b >> w;
            --a; --b;
            edges.pb({w, a, b, i});
        }

        sort(all(edges));

        DSU dsu(n);

        ll mst = 0;
        int added = 0;
        int j = 0;
        while (added != n - 1){
            auto &[w, a, b, i] = edges[j];

            if (!dsu.connected(a, b)){
                mst += (ll) w;
                adj[a].pb({b, w});
                adj[b].pb({a, w});
                dsu.unite(a, b);

                added++;
            }

            j++;
        }

        LCA lca(n, adj);

        int lg = log2(n) + 1;
        vector<vector<pii>> jump(n, vector<pii>(lg, {-1, 0}));

        rep(i, 1, n){
            jump[i][0] = lca.parent(i);
        }

        rep(l, 1, lg){
            rep(i, 0, n){
                pii jp1 = jump[i][l - 1];
                if (jp1.first == -1) continue;
                pii jp2 = jump[jp1.first][l - 1];
                if (jp2.first == -1) continue;
                jump[i][l] = {jp2.first, max(jp1.second, jp2.second)};
            }
        }

        vl ans(m);

        rep(i, 0, m){
            auto &[w, a, b, j] = edges[i];

            int l = lca.lca(a, b);
            int d = lca.depth(l);
            ll mx1 = 0, mx2 = 0;

            int d1 = lca.depth(a) - d;
            int at = a;
            rep(k, 0, lg){
                if (d1 & (1 << k)){
                    mx1 = max(mx1, (ll) jump[at][k].second);
                    at = jump[at][k].first;
                }
            }
            
            int d2 = lca.depth(b) - d;
            at = b;
            rep(k, 0, lg){
                if (d2 & (1 << k)){
                    mx2 = max(mx2, (ll) jump[at][k].second);
                    at = jump[at][k].first;
                }
            }

            ans[j] = mst + (ll)(w) - (ll) max(mx1, mx2);
        }

        for (ll a : ans){
            cout << a << endl;
        }
    }

    int main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0); cout.tie(0);
        solve();
        return 0;
    }