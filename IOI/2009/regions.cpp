/**
 * Solution by 1egend (polarity.sh)
 * Date: 2025-02-15
 * Contest: IOI 2009
 * Problem: regions
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
 * ALGORITHM: Euler Tour
 * PURPOSE: Flattens a tree so that each range contains any subtree range
 * CONSTRAINT: Graph must be a tree
 * TIME: O(V)
*/
vector<pii> eulerTour(int n, vector<vector<int>> &adj){
    vector<pii> ans(n);
    int i = -1;
    function<void(int, int)> tour;
    tour = [&](int node, int parent){
        ans[node].first = ++i;
        for (int x : adj[node]){
            if (x != parent){
                tour(x, node);
            }
        }
        ans[node].second = i;
    };

    // root at 0
    tour(0, 0);

    return ans;
}

void solve(){
    int n, r, q; cin >> n >> r >> q;
    int rt = sqrt(n);
    vector<vi> adj(n);
    vi region(n);
    rep(i, 0, n){
        if (i == 0){
            cin >> region[0];
            region[0]--;
            continue;
        }

        int s; cin >> s;
        --s;
        adj[i].pb(s);
        adj[s].pb(i);

        cin >> region[i];
        region[i]--;
    }

    vector<pii> tree = eulerTour(n, adj);

    vector<vi> regions(r);
    vi count(r, 0);
    vi rend(n);
    vi arr(n);
    rep(i, 0, n){
        count[region[i]]++;
        regions[region[i]].pb(tree[i].first);
        arr[tree[i].first] = region[i];
        rend[tree[i].first] = tree[i].second;
    }

    vi idx(r);
    int k = 0;

    rep(i, 0, r){
        sort(all(regions[i]));
        if (count[i] > rt){
            idx[i] = k;
            k++;
        }
    }

    vi curr(k, 0);
    vector<vector<int>> ans(k, vector<int>(r, 0));

    using T = pii;
    priority_queue<T, vector<T>, greater<T>> pq;

    rep(i, 0, n){
        int a = arr[i];
        if (count[a] > rt){
            pq.push(pii{rend[i], idx[a]});
            curr[idx[a]]++;
        }

        while(!pq.empty() && pq.top().first < i){
            curr[pq.top().second]--;
            pq.pop();
        }

        rep(j, 0, k){
            ans[j][a] += curr[j];
        }
    }


    rep(i, 0, q){
        int r1, r2; cin >> r1 >> r2;
        --r1; --r2;
        if (count[r1] > rt){
            cout << ans[idx[r1]][r2] << endl;
            continue;
        }

        int a = 0;
        rep(j, 0, regions[r1].size()){
            int s = regions[r1][j];
            int e = rend[s];
            a += upper_bound(all(regions[r2]), e) - upper_bound(all(regions[r2]), s);
        }

        cout << a << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}