/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-08-25
 * Contest: Codeforces 2133
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

// got the idea but too lazy to implement
void solve(){
    int n; cin >> n;
    vector<set<int>> adj(n);
    vi deg(n, 0);
    rep(i, 0, n - 1){
        int a, b; cin >> a >> b;
        --a; --b;
        adj[a].insert(b);
        adj[b].insert(a);
        deg[a]++;
        deg[b]++;
    }

    vector<pii> ans;

    auto re = [&](int x){
        ans.pb({2, x});
        for (int el : adj[x]){
            adj[el].erase(x);
            deg[el]--;
        }

        adj[x] = {};
        deg[x] = 0;
    };

    rep(i, 0, n){
        if (deg[i] >= 4){
            re(i);
        }
    }

    auto dfs = [&](int x, int par){
        for (int el : adj[x]){
            if (el == par) continue;
            dfs(el, x);
        }

        
    };

    rep(i, 0, n){

    }

    cout << ans.size() << endl;
    for (pii el : ans){
        cout << el.first << " " << el.second << endl;
    }
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