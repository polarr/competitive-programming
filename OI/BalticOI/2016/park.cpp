/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-03-08
 * Contest: Baltic OI 2016
 * Problem: park
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

struct Edge {
    int i, j;
    long double w;
    bool operator<(const Edge &e) const { return w < e.w; }
};

void solve(){
    int n, m; cin >> n >> m;
    long double w, h; cin >> w >> h;

    vector<Edge> edges;
    vector<array<long double, 3>> circles(n);

    rep(i, 0, n){
        long double x, y, r;
        cin >> x >> y >> r;

        circles[i] = {x, y, r};
    }

    rep(i, 0, n){
        auto &[x, y, r] = circles[i];
        edges.pb({0, i + 4, (long double)x - r});
        edges.pb({1, i + 4, h - y - r});
        edges.pb({2, i + 4, w - x - r});
        edges.pb({3, i + 4, (long double)y - r});
    }

    rep(i, 0, n){
        rep(j, i + 1, n){
            Edge e;
            e.i = i + 4; e.j = j + 4;

            long double xx = circles[i][0] - circles[j][0];
            long double yy = circles[i][1] - circles[j][1];

            e.w = sqrt(xx * xx + yy * yy) - circles[i][2] - circles[j][2];
            edges.pb(e);
        }
    }

    sort(all(edges));

    vector<array<int, 3>> visitors(m);

    rep(i, 0, m){
        int r, e; cin >> r >> e;
        visitors[i] = {2 * r, e, i};
    }

    sort(all(visitors));

    int j = 0;

    DSU dsu(n + 4);

    vector<array<bool, 4>> ans(m);

    rep(i, 0, m){
        auto &[r, e, idx] = visitors[i];
        while (j < edges.size() && edges[j].w < (long double) r){
            dsu.unite(edges[j].i, edges[j].j);
            j++;
        }

        bool c01 = dsu.connected(0, 1);
        bool c02 = dsu.connected(0, 2);
        bool c03 = dsu.connected(0, 3);
        bool c12 = dsu.connected(1, 2);
        bool c13 = dsu.connected(1, 3);
        bool c23 = dsu.connected(2, 3);

        bool cant1 = false;
        bool cant2 = false;
        bool cant3 = false;
        bool cant4 = false;

        if (e == 1){
            cant2 = c03 || c13 || c23;
            cant3 = c03 || c13 || c02 || c12;
            cant4 = c03 || c02 || c01;
        } else if (e == 2){
            cant1 = c23 || c13 || c03;
            cant3 = c23 || c02 || c12;
            cant4 = c23 || c02 || c13 || c01;
        } else if (e == 3){
            cant1 = c12 || c02 || c13 || c03;
            cant2 = c12 || c02 || c23;
            cant4 = c12 || c13 || c01;
        } else {
            cant1 = c01 || c02 || c03;
            cant2 = c01 || c02 || c13 || c23;
            cant3 = c01 || c13 || c12;
        }

        ans[idx] = {!cant1, !cant2, !cant3, !cant4};
    }

    rep(i, 0, m){
        string a = "";
        if (ans[i][0]) a += "1";
        if (ans[i][1]) a += "2";
        if (ans[i][2]) a += "3";
        if (ans[i][3]) a += "4";

        cout << a << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}