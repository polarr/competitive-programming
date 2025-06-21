/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-06-20
 * Contest: Codeforces 1779
 * Problem: F
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

// this is so simple how 2500.. E is harder imo
void solve(){
    int n; cin >> n;

    vi a(n);
    rep(i, 0, n) cin >> a[i];

    vi parent(n, -1);
    vector<vi> children(n);

    rep(i, 1, n){
        int p; cin >> p;
        --p;

        parent[i] = p;
        children[p].pb(i);
    }

    vector<vector<bool>> dp(n, vector<bool>(32, false));
    vector<vector<vector<bool>>> dpcurr(n);
    vi subtr(n, 1);

    function<void(int)> dfs;

    dfs = [&](int x){
        vector<bool> curr(32, false);
        curr[a[x]] = true;
        dpcurr[x] = vector<vector<bool>>(children[x].size());
        rep(i, 0, children[x].size()){
            int node = children[x][i];
            dfs(node);
            subtr[x] += subtr[node];

            dpcurr[x][i] = curr;
            vector<bool> ncurr(32, false);
            rep(j, 0, 32){
                if (!curr[j]) continue;
                rep(k, 0, 32){
                    if (!dp[node][k]) continue;
                    ncurr[j ^ k] = true;
                }
            }
            curr = ncurr;
        }

        if (subtr[x] % 2 == 0){
            curr[0] = true;
        }

        dp[x] = curr;
    };

    dfs(0);

    if (!dp[0][0]){
        cout << -1 << endl;
        return;
    }

    vi ans;

    function<void(int, int)> dfsans;

    dfsans = [&](int x, int want){
        if (subtr[x] % 2 == 0 && want == 0){
            ans.pb(x);
            return;
        }

        int w = want;
        for (int i = children[x].size() - 1; i >= 0; i--){
            int node = children[x][i];
            rep(j, 0, 32){
                if (!dpcurr[x][i][j]) continue;
                bool broken = false;
                rep(k, 0, 32){
                    if (!dp[node][k]) continue;
                    if ((j ^ k) == w){
                        dfsans(node, k);
                        w = j;
                        broken = true;
                        break;
                    }
                }

                if (broken) break;
            }
        }
    };

    dfsans(0, 0);
    ans.pb(0);

    cout << ans.size() << endl;
    for (int v : ans){
        cout << v + 1 << " ";
    }

    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}