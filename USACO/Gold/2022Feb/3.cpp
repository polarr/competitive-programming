/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-11-14
 * Contest: USACO 2022 Feb Gold
 * Problem: 3
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
    int n; cin >> n;

    DSU g(n);

    vector<set<pair<ll, int>>> locations(11);

    pair<ll, ll> curr;
    int currIndex = 0;

    for (int i = 0; i < n; i++){
        ll x, y; cin >> x >> y;

        if (i == 0) {curr = {x, y}; continue;}

        locations[y].insert({x, i});
    }

    ll ans = 0;

    auto valid = [&](int j, set<pair<ll, int>>::iterator ptr){
        if (ptr == locations[j].end() || g.connected((*ptr).second, currIndex)){
            return false;
        }

        return true;
    };

    for (int i = 0; i < n - 1; i++){
        pair<ll, ll> target;
        int targetIndex;
        ll minDist = LLONG_MAX;
        for (int j = 0; j < 11; j++){
            auto right = locations[j].upper_bound({curr.first, -1});

            if (right != locations[j].end() && !g.connected((*right).second, currIndex)){
                pair<ll, int> r = *right;
                ll dist = pow(target.first - r.first, 2) + pow(target.second - j, 2);
                if (dist < minDist){
                    minDist = dist;
                    target = {r.first, j};
                    targetIndex = r.second;
                }
            }

            if (right != locations[j].begin() && !g.connected((*prev(right)).second, currIndex)){
                pair<ll, int> l = *prev(right);
                ll dist = pow(target.first - l.first, 2) + pow(target.second - j, 2);
                if (dist < minDist){
                    minDist = dist;
                    target = {l.first, j};
                    targetIndex = l.second;
                }
            }
        }

        cout << minDist << endl;
        ans += minDist;
        locations[target.second].erase({target.first, targetIndex});
        g.unite(currIndex, targetIndex);
        curr = target;
        currIndex = targetIndex;
    }

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}