/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-04-18
 * Contest: Codeforces 1810
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
        int mxSize = 1;
    
    public:
        DSU(int size) : parents(size), sizes(size, 1){
            for (int i = 0; i < size; i++){
                parents[i] = i;
            }
        }

        int find(int x){
            return (parents[x] == x ? x : (parents[x] = find(parents[x])));
        }

        int maxSize(){
            return maxSize;
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
            mxSize = max(mxSize, sizes[parentB]);
            parents[parentA] = parentB;
            return true;
        }

        bool connected(int a, int b){
            return find(a) == find(b);
        }
};

void solve(){
    int n, m; cin >> n >> m;

    map<int, bool> hasDanger;
    vi danger(n);
    rep(i, 0, n){
        cin >> danger[i];
        hasDanger[danger[i]] = true;
    }
    map<int, vector<pii>> edges;
    rep(i, 0, m){
        int a, b; cin >> a >> b;
        --a; --b;
        edges[max(danger[a], danger[b])].pb({a, b});
    }

    DSU dsu(n);

    rep(i, 1, n){
        if (hasDanger[i]){
            if (dsu.maxSize() < danger[i]){
                
            }
        }

        for (pii edge : edges[i]){

        }
    }

    cout << "YES" << endl;
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