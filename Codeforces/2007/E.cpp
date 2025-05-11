/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-05-10
 * Contest: Codeforces 2007
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
        vector<set<int>> group;
        int untaken;
        int n;
    
    public:
        DSU(int size) : parents(size), sizes(size, 1), group(size){
            n = size;
            untaken = size;
            for (int i = 0; i < size; i++){
                parents[i] = i;
                group[i].insert(i);
            }
        }

        int getUntaken(){
            return untaken;
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
            for (int node : group[parentA]){
                if (group[parentB].contains((node + n - 1) % n)) untaken--;
                if (group[parentB].contains((node + 1) % n)) untaken--;
            }
            for (int node : group[parentA]){
                group[parentB].insert(node);
            }
            parents[parentA] = parentB;
            return true;
        }

        bool connected(int a, int b){
            return find(a) == find(b);
        }
};


void solve(){
    int n; cin >> n;
    ll w; cin >> w;

    vi par(n, -1);
    rep(i, 1, n) {
        int p; cin >> p;
        --p;
        par[i] = p;
    }

    DSU dsu(n);

    ll known = 0;
    rep(i, 0, n - 1){
        int b; ll y;
        cin >> b >> y;
        --b;
        int a = par[b];

        known += y;
        dsu.unite(a, b);
        cout << 2 * known + (w - known) * (ll) dsu.getUntaken() << " ";
    }

    cout << endl;
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