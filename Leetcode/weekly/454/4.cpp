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

class Solution {
public:
    vector<int> findMedian(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        vector<vector<pair<int, ll>>> adj(n);
        vi ans;
        rep(i, 0, n - 1){
            int a = edges[i][0];
            int b = edges[i][1];
            ll c = edges[i][2];

            adj[a].pb({b, c});
            adj[b].pb({a, c});
        }

        int lg = log2(n) + 1;
        vector<vector<pair<int, ll>>> jump(n, vector<pair<int, ll>>(lg, {-1, 0}));

        vi depth(n, 0);

        function<void(int, int)> dfs;
        dfs = [&](int x, int par){
            for (auto [node, w] : adj[x]){
                if (node == par) continue;

                jump[node][0] = {x, w};
                depth[node] = depth[x] + 1;
                dfs(node, x);
            }
        };

        dfs(0, -1);

        rep(i, 1, lg){
            rep(j, 0, n){
                pair<int, ll> jp1 = jump[j][i - 1];
                if (jp1.first == -1) continue;
                pair<int, ll> jp2 = jump[jp1.first][i - 1];
                jump[j][i] = {jp2.first, jp1.second + jp2.second};
            }
        }

        rep(i, 0, queries.size()){
            int a = queries[i][0];
            int b = queries[i][1];

            if (a == b){
                ans.pb(a);
                continue;
            }

            int aa = a, bb = b;
            if (depth[aa] > depth[bb]){
                swap(aa, bb);
            }

            int lca = bb;
            int d = depth[bb] - depth[aa];
            rep(j, 0, lg){
                if (d & (1 << j)){
                    lca = jump[lca][j].first;
                }
            }

            if (lca != aa){
                for (int j = lg - 1; j >= 0; j--){
                    if (jump[aa][j].first != jump[lca][j].first){
                        aa = jump[aa][j].first;
                        lca = jump[lca][j].first;
                    }
                }

                lca = jump[lca][0].first;
            }

            ll pa = 0, pb = 0;
            int da = depth[a] - depth[lca];
            int db = depth[b] - depth[lca];

            aa = a, bb = b;

            rep(j, 0, lg){
                if (da & (1 << j)){
                    pa += jump[aa][j].second;
                    aa = jump[aa][j].first;
                }

                if (db & (1 << j)){
                    pb += jump[bb][j].second;
                    bb = jump[bb][j].first;
                }
            }

            ll total = pa + pb;
            int xx = 0;
            
            if (pa >= 1.0 * total/2){
                ll curr = 0;
                xx = a;
                for (int j = lg - 1; j >= 0; j--){
                    if (jump[xx][j].first == -1) continue;
                    if (curr + jump[xx][j].second < 1.0 * total/2){
                        curr += jump[xx][j].second;
                        xx = jump[xx][j].first;
                    }
                }

                xx = jump[xx][0].first;
            } else {
                ll curr = 0;
                xx = b;
                for (int j = lg - 1; j >= 0; j--){
                    if (jump[xx][j].first == -1) continue;
                    if (curr + jump[xx][j].second <= 1.0 * total/2){
                        curr += jump[xx][j].second;
                        xx = jump[xx][j].first;
                    }
                }
            }

            ans.pb(xx);
        }

        return ans;
    }
};