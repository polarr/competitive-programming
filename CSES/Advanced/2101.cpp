/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-03-08
 * Contest: CSES Problemset
 * Problem: 2101
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

// Maybe unintended idea?

class DSU {
    public: 
        vector<int> parents;
        vector<int> sizes;
        vector<vi> currentNodes;
        vector<vector<pair<int, int>>> parentHistory;
    
        DSU(int size) : parents(size), sizes(size, 1), currentNodes(size), parentHistory(size){
            for (int i = 0; i < size; i++){
                parents[i] = i;
                parentHistory[i].pb({i, 0});
                currentNodes[i].pb(i);
            }
        }

        DSU(vector<int> p, vector<int> s){
            parents = p;
            sizes = s;
        }

        DSU clone(){
            return DSU(parents, sizes);
        }

        int find(int x){
            return (parents[x] == x ? x : (parents[x] = find(parents[x])));
        }

        int componentCount(){
            int ans = 0;
            for (int i = 0; i < parents.size(); i++){
                if (parents[i] == i){
                    ans++;
                    //cout << i << endl;
                }
            }

            return ans;
        }

        bool unite(int a, int b, int i){
            int parentA = find(a);
            int parentB = find(b);
            if (parentA == parentB){
                return false;
            }

            if (sizes[parentA] > sizes[parentB]){
                swap(parentA, parentB);
            }

            sizes[parentB] += sizes[parentA];
            for (int x : currentNodes[parentA]){
                parentHistory[x].pb({parentB, i});
                currentNodes[parentB].pb(x);
            }
            parents[parentA] = parentB;
            return true;
        }

        int findLast(int a, int b){
            int szA = parentHistory[a].size();
            int szB = parentHistory[b].size();
            pii lastA = parentHistory[a][szA - 1];
            pii lastB = parentHistory[b][szB - 1];

            if (lastA.first != lastB.first){
                return -1;
            }

            int low = 1, high = min(szA, szB);

            while (low < high){
                int mid = (low + high + 1)/2;

                pii testA = parentHistory[a][szA - mid];
                pii testB = parentHistory[b][szB - mid];

                if (testA.first == testB.first){
                    low = mid;
                } else {
                    high = mid - 1;
                }
            }

            return max(parentHistory[a][szA - low].second, parentHistory[b][szB - low].second);
        }

        bool connected(int a, int b){
            return find(a) == find(b);
        }
};

void solve(){
    int n, m, q; cin >> n >> m >> q;
    
    DSU dsu(n);

    rep(i, 0, m){
        int a, b; cin >> a >> b;
        --a; --b;
        dsu.unite(a, b, i + 1);
    }

    rep(i, 0, q){
        int a, b; cin >> a >> b;
        --a; --b;
        dsu.findLast(a, b);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}