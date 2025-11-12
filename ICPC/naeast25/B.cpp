#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using vi = vector<int>;
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define sz(a) (int)(a).size()
#define pb push_back

const int INF = 1e6;

void solve(){
    int n; cin >> n;
    char t; cin >> t;

    vi op(2, 0);
    // and = 1, or = 0
    if (t == 'A'){
        op[0] = 1;
    } else {
        op[1] = 1;
    }

    vi vals;
    vi par;
    vector<vi> children;
    int curr = 0;
    vi expect = {-1};
    rep(i, 0, n){
        vi nexpect;
        rep(j, 0, sz(expect)){
            int p = expect[j];
            string s; cin >> s;
            
            children.pb({});
            if (p != -1) children[p].pb(curr);
            par.pb(p);
    
            if (s == "F"){
                vals.pb(0);
            } else if (s == "T"){
                vals.pb(1);
            } else {
                int k = stoi(s);
                vals.pb(-1);
                rep(kk, 0, k){
                    nexpect.pb(curr);
                }
            }
            curr++;
        }

        expect = nexpect;
    }

    n = sz(par);

    vi depth(n, 0);
    function<void(int)> dfs_vals, dfs;
    dfs_vals = [&](int node){
        int o = op[depth[node]];
        if (vals[node] == -1){
            vals[node] = o;
        }

        for (int x : children[node]){
            depth[x] = 1 - depth[node];
            dfs_vals(x);

            if (o == 1){
                vals[node] &= vals[x];
            } else {
                vals[node] |= vals[x];
            }
        }
    };

    dfs_vals(0);
    vi dp(n, 0);

    dfs = [&](int node){
        int o = op[depth[node]];
        if (sz(children[node]) == 0){
            dp[node] = 1;
            return;
        }

        if (o == 1 && vals[node] == 1){
            // AND = true
            dp[node] = INF;
        }

        if (o == 0 && vals[node] == 0){
            dp[node] = INF;
        }

        for (int x : children[node]){
            dfs(x);
            if (o == 1 && vals[node] == 0){
                // AND = false
                if (vals[x] == 0){
                    dp[node] += dp[x];
                }
            }

            if (o == 1 && vals[node] == 1){
                // AND = true
                dp[node] = min(dp[node], dp[x]);
            }

            if (o == 0 && vals[node] == 1){
                // OR = true
                if (vals[x] == 1){
                    dp[node] += dp[x];
                }
            }

            if (o == 0 && vals[node] == 0){
                // OR = false
                dp[node] = min(dp[node], dp[x]);
            }
        }
    };

    dfs(0);

    cout << dp[0] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}   