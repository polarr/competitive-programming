/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-12-23
 * Contest: 
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

void first(){
    int n, m; cin >> n >> m;
    vector<vi> adj(n);
    rep(i, 0, m) {
        int a, b; cin >> a >> b;
        --a; --b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    vi dist(n, -1);
    dist[0] = 0;
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int x : adj[node]) {
            if (dist[x] == -1) {
                dist[x] = 1 + dist[node];
                q.push(x);
            }
        }
    }

    rep(i, 0, n) {
        if (dist[i] % 3 == 0) {
            cout << "r";
        } else if (dist[i] % 3 == 1) {
            cout << "g";
        } else {
            cout << "b";
        }
    }

    cout << endl;
}

void second(){
    int q; cin >> q;
    rep(qq, 0, q) {
        int d; cin >> d;
        string s; cin >> s;

        int r = -1, g = -1, b = -1;

        rep(i, 0, d) {
            if (s[i] == 'r') {
                r = i;
            } else if (s[i] == 'g') {
                g = i;
            } else {
                b = i;
            }
        }

        if (g == -1 && b == -1) {
            cout << r + 1 << '\n';
            continue;
        } else if (r == -1 && b == -1) {
            cout << g + 1 << '\n';
            continue;
        } else if (r == -1 && g == -1) {
            cout << b + 1 << '\n';
            continue;
        }

        if (r == -1) {
            cout << b + 1 << '\n';
            continue;
        }

        if (g == -1) {
            cout << r + 1 << '\n';
            continue;
        }

        if (b == -1) {
            cout << g + 1 << '\n';
            continue;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    string s; cin >> s;
    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; ++t){
        if (s == "first") {
            first();
        } else {
            second();
        }
    }
    return 0;
}