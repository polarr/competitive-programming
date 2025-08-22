/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-08-21
 * Contest: CSES
 * Problem: 3359
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
    int n; cin >> n;

    vector<vector<char>> grid(n, vector<char>(n));

    rep(i, 0, n){
        string s; cin >> s;
        rep(j, 0, n){
            grid[i][j] = s[j];
        }
    }
    
    vector<vector<bool>> visited(n, vector<bool>(n, false));

    visited[0][0] = true;
    stack<pii> q;
    q.push({0, 0});

    string ans = "";
    ans += grid[0][0];


    char mn = 'Z';
    stack<pii> nq;

    auto walk = [&](pii a){
        if (a.first >= n || a.second >= n || visited[a.first][a.second]) return;
        visited[a.first][a.second] = true;
        char x = grid[a.first][a.second];
        if (x > mn) return;
        if (x < mn){
            mn = x;
            nq = {};
        }

        nq.push(a);
    };

    rep(i, 0, 2 * n - 2){
        mn = 'Z';
        nq = {};
        while (!q.empty()){
            pii at = q.top();
            q.pop();

            pii a = {at.first, at.second + 1}, b = {at.first + 1, at.second};

            walk(a);
            walk(b);
        }

        q = nq;
        ans += mn;
    }

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}