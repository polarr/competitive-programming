/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-04-10
 * Contest: ICPC Practice Codeforces 597340
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

void solve(){
    int n, m; cin >> n >> m;

    vector<vector<pii>> adj1(n);
    vector<vector<pii>> adj2(n);

    auto encode = [&](int x, int y){
        return x * 5000 + y;
    };

    auto decode = [&](int z){
        return pii{z/5000, z % 5000};
    };

    vector<bool> visited(n * 5000, false);

    int ans = 0;
    queue<int> q;

    rep(i, 0, n){
        visited[encode(i, i)] = true;
        q.push(encode(i, i));
    }

    rep(i, 0, m){
        int x, y; char c;
        cin >> x >> y >> c;
        --x; --y;
        int z = c - 'a';
        if (!visited[encode(x, y)]){
            ans++;
            visited[encode(x, y)] = true;
            q.push(encode(x, y));
        }
        adj1[x].pb({y, z});
        adj2[y].pb({x, z});
    }

    while (!q.empty()){
        int x = q.front();
        q.pop();

        pii p = decode(x);

        for (auto &[a, c1] : adj2[p.first]){
            for (auto [b, c2] : adj1[p.second]){
                if (c1 == c2){
                    int node = encode(a, b);
                    if (visited[node]) continue;
                    visited[node] = true;
                    ans++;
                    q.push(node);
                }
            }
        }
    }

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}