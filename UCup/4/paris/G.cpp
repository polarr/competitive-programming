/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-10-25
 * Contest: 
 * Problem: G
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

        int size(int a){
            return sizes[find(a)];
        }
};

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

int pick(int lo, int hi){
    return uniform_int_distribution<ll>(lo, hi)(rng);
}

void solve(){
    int n, m, q;
    cin >> n >> m >> q;

    int need = 20000;

    DSU dsu(n);
    vector<vi> adj(n);

    int mx = 100;
    vector<vi> inRange(mx, vi(n, 1e8));

    rep(i, 0, m){
        int a, b; cin >> a >> b;
        --a; --b;
        adj[a].pb(b);
        adj[b].pb(a);

        dsu.unite(a, b);
    }

    vector<bool> visited(n, false);
    rep(k, 0, mx){
        int p = pick(0, n - 1);

        if (dsu.size(p) <= need){
            continue;
        }
        
        vi vis;
        queue<pii> q;
        q.push({p, 0});

        while (!q.empty()){
            auto [x, dist] = q.front();
            q.pop();

            if (visited[x]) continue;

            visited[x] = true;
            vis.pb(x);
            inRange[k][x] = dist;

            for (int node : adj[x]){
                if (visited[node]) continue;
                if (dist + 1 > need){
                    continue;
                }

                q.push({node, dist + 1});
            }
        }

        for (int x : vis){
            visited[x] = false;
        }
    }

    rep(i, 0, q){
        int a, b; cin >> a >> b;
        --a; --b;

        if (!dsu.connected(a, b)){
            cout << "YES" << endl;
            continue;
        }

        if (dsu.size(a) <= need){
            cout << "NO" << endl;
            continue;
        }

        bool flag = false;

        rep(j, 0, mx){
            if (inRange[j][a] + inRange[j][b] <= need){
                cout << "NO" << endl;
                flag = true;
                break;
            }
        }

        if (flag) continue;

        cout << "YES" << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}