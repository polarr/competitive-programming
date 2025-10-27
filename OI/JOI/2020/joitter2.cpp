/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-10-26
 * Contest: JOI 2020
 * Problem: joitter2
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
        vector<ll> sizes;
        vector<map<int, ll>> from;
        vector<set<int>> fromEl;
        vector<set<pii>> to;
        vector<set<int>> els;
        ll ans = 0;
    
    public:
        DSU(int size) : parents(size), sizes(size, 1), from(size), fromEl(size), to(size), els(size){
            for (int i = 0; i < size; i++){
                parents[i] = i;
                els[i].insert(i);
            }
        }

        int find(int x){
            return (parents[x] == x ? x : (parents[x] = find(parents[x])));
        }

        ll completeCount(ll x){
            return sizes[x] * (sizes[x] - 1);
        }

        void merge(int a, int b){
            int parentA = find(a);
            int parentB = find(b);
            if (parentA == parentB){
                return;
            }

            // merge these
            ans -= from[parentA][parentB] * sizes[parentA];
            ans -= from[parentB][parentA] * sizes[parentB];
            ans -= completeCount(parentA);
            ans -= completeCount(parentB);

            if (sizes[parentA] > sizes[parentB]){
                swap(parentA, parentB);
            }
            
            for (int x : els[parentA]){
                if (fromEl[parentB].contains(x)){
                    fromEl[parentB].erase(x);
                    to[parentA].erase({x, parentB});
                }

                els[parentB].insert(x);
            }

            ans += sizes[parentA] * (ll)sz(fromEl[parentB]);

            vi merges;

            for (int x : fromEl[parentA]){
                int parentX = find(x);
                to[parentX].erase({x, parentA});
                if (parentX == parentB) continue;

                if (fromEl[parentB].contains(x)){
                    ans -= sizes[parentA];
                    continue;
                }

                if (from[parentX][parentB] > 0){
                    merges.pb(parentX);
                }

                to[parentX].insert({x, parentB});
                from[parentB][parentX]++;
                fromEl[parentB].insert(x);
                ans += sizes[parentB];
            }

            fromEl[parentA] = {};

            for (auto& [el, comp] : to[parentA]){
                if (from[parentB][comp] > 0){
                    merges.pb(comp);
                }

                from[comp][parentB]++;
                from[comp].erase(parentA);
                to[parentB].insert({el, comp});
            }

            to[parentA] = {};

            sizes[parentB] += sizes[parentA];
            parents[parentA] = parentB;

            ans += completeCount(parentB);      

            for (int comp : merges){
                merge(parentB, comp);
            }
        }

        bool unite(int a, int b){
            int parentA = find(a);
            int parentB = find(b);
            if (parentA == parentB){
                return false;
            }

            if (from[parentA][parentB] == 0){
                if (!fromEl[parentB].contains(a)){
                    from[parentB][parentA]++;
                    ans += sizes[parentB];
                }
                to[parentA].insert({a, parentB});
                fromEl[parentB].insert(a);

                return false;
            }

            merge(parentA, parentB);
            return true;
        }

        bool connected(int a, int b){
            return find(a) == find(b);
        }

        ll answer(){
            return ans;
        }
};

void solve(){
    int n, m; cin >> n >> m;
    
    DSU dsu(n);
    rep(i, 0, m){
        int a, b; cin >> a >> b;
        --a; --b;

        dsu.unite(a, b);

        cout << dsu.answer() << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}