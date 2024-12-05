/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-11-14
 * Contest: USACO 2021 Open Gold
 * Problem: 2
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
        int componentCount;
    
    public:
        DSU(int size) : parents(size), sizes(size, 1){
            componentCount = size;
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

            componentCount--;

            if (sizes[parentA] > sizes[parentB]){
                swap(parentA, parentB);
            }

            sizes[parentB] += sizes[parentA];
            parents[parentA] = parentB;
            return true;
        }

        bool allConnected(){
            return (componentCount == 1);
        }

        bool connected(int a, int b){
            return find(a) == find(b);
        }
};

void solve(){
    int n; cin >> n;

    DSU g(2 * n);
    vector<array<int, 3>> edges;
    for (int i = 0; i < n; i++){
        int c, p1, p2, p3, p4;
        cin >> c >> p1 >> p2 >> p3 >> p4;
        --p1; --p2; --p3; --p4;

        edges.pb({c, p1, p3});
        edges.pb({0, p1, p2});
        edges.pb({0, p3, p4});
    }

    sort(edges.begin(), edges.end());

    int ans = 0;

    for (int i = 0; i < 3 * n; i++){
        array<int, 3> edge = edges[i];
        if (!g.connected(edge[1], edge[2])){
            g.unite(edge[1], edge[2]);
            ans += edge[0];
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