/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-11-13
 * Contest: CSES Problemset - Graph Algorithms
 * Problem: 1675
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

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

    if (n == 1){
        cout << 0 << endl;
        return;
    }

    DSU g(n);

    vector<tuple<int, int, int>> edges;
    for (int i = 0; i < m; i++){
        int a, b, c; cin >> a >> b >> c;
        --a; --b;
        edges.pb({c, a, b});
    }

    sort(edges.begin(), edges.end());

    ll cost = 0;
    int count = 0;

    for (int i = 0; i < m; i++){
        tuple<int, int, int> edge = edges[i];
        if (g.connected(get<1>(edge), get<2>(edge))){
            continue;
        }


        count++;
        cost += (ll)get<0>(edge);
        g.unite(get<1>(edge), get<2>(edge));
    }

    if (count != n - 1){
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    cout << cost << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}