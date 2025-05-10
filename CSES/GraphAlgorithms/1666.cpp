/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-05-09
 * Contest: CSES Problemset
 * Problem: 1666
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

void solve(){
    int n, m; cin >> n >> m;

    DSU dsu(n);

    int ans = n;

    rep(i, 0, m){
        int a, b; cin >> a >> b;
        --a; --b;
        if (!dsu.connected(a, b)){
            dsu.unite(a, b);
            --ans;
        }
    }

    cout << ans - 1 << endl;

    vi leaders;
    rep(i, 0, n){
        if (dsu.find(i) == i){
            leaders.pb(i);
        }
    }

    rep(i, 1, leaders.size()){
        cout << leaders[0] + 1 << " " << leaders[i] + 1 << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}