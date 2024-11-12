/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-11-12
 * Contest: CSES Problemset - Graph Algorithms
 * Problem: 1676
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
        int maxSize;
    
    public:
        DSU(int size) : parents(size), sizes(size, 1){
            componentCount = size;
            maxSize = 1;
            for (int i = 0; i < size; i++){
                parents[i] = i;
            }
        }

        int find(int x){
            return (parents[x] == x ? x : (parents[x] = find(parents[x])));
        }

        int getComponentCount(){
            return componentCount;
        }

        int getMaxSize(){
            return maxSize;
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

            maxSize = max(maxSize, sizes[parentB]);
            return true;
        }

        bool connected(int a, int b){
            return find(a) == find(b);
        }
};

void solve(){
    int n, m; cin >> n >> m;

    DSU g(n);

    for (int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        --a; --b;
        g.unite(a, b);
        cout << g.getComponentCount() << " " << g.getMaxSize() << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}