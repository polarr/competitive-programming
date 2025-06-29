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

const int MAX_N = 5e5 + 1;
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

class Solution {
public:
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        DSU dsu(n);
        int m = edges.size();
        int connect = n - 1;
        int minUpgrade = INT_MAX;
        vi spanning;
        rep(i, 0, m){
            swap(edges[i][2], edges[i][0]);
        }
        sort(all(edges));
        rep(i, 0, m){
            if (edges[i][3] == 1){
                if (!dsu.unite(edges[i][2], edges[i][1])){
                    return -1;
                }

                minUpgrade = min(minUpgrade, edges[i][0]);
                connect--;
            }
        }

        int j = m - 1;
        while (connect > 0){
            if (j == -1){
                return -1;
            }

            if (edges[j][3] == 1){
                j--;
                continue;
            }

            if (!dsu.unite(edges[j][1], edges[j][2])){
                j--;
                continue;
            }

            connect--;
            spanning.pb(edges[j][0]);
        }

        sort(all(spanning));

        int ans = minUpgrade;
        if (spanning.size() > 0){
            ans = min(ans, spanning[0] * 2);
        }

        if (spanning.size() > k){
            ans = min(ans, spanning[k]);
        }

        return ans;
    }
    
};