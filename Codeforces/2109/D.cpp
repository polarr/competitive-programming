/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-05-17
 * Contest: Codeforces 2109
 * Problem: D
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

void solve(){
    int n, m, l; cin >> n >> m >> l;

    vi a(l);
    int sum = 0;
    int smallodd = 1e9;
    rep(i, 0, l){
        cin >> a[i];
        sum += a[i];
        if (a[i] % 2 == 1){
            smallodd = min(smallodd, a[i]);
        }
    }

    vector<vi> adj(n);
    rep(i, 0, m){
        int a, b; cin >> a >> b;
        --a; --b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    vl deven(n, INT_MAX);
    vl dodd(n, INT_MAX);

    deven[0] = 0;
    
    vector<array<bool, 2>> visited(n, {false, false});

    queue<pii> q;
    q.push({0, 0});

    while (!q.empty()){
        auto [x, par] = q.front();
        q.pop();

        if (visited[x][par]){
            continue;
        }

        visited[x][par] = true;

        for (int node : adj[x]){
            if (par == 0){
                if (deven[x] + 1 < dodd[node]){
                    dodd[node] = deven[x] + 1;
                    q.push({node, 1});
                }
            } else {
                if (dodd[x] + 1 < deven[node]){
                    deven[node] = dodd[x] + 1;
                    q.push({node, 0});
                }
            }
        }
    }

    ll maxeven = -1, maxodd = -1;
    if (smallodd == 1e9){
        maxeven = sum;
    } else {
        if (sum % 2 == 0){
            maxeven = sum;
            maxodd = sum - smallodd;
        } else {
            maxodd = sum; 
            maxeven = sum - smallodd;
        }
    }

    string ans = "";

    rep(i, 0, n){
        //cout << dodd[i] << deven[i] << endl;
        if (dodd[i] <= maxodd || deven[i] <= maxeven){
            ans += "1";
        } else {
            ans += "0";
        }
    }

    cout << ans << endl;
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