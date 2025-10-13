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

vector<pii> cardinal = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void solve() {
    int r, c; cin >> r >> c;
    int n; cin >> n;
    
    vector<pii> towers(n);
    vector<vector<pii>> ans(r, vector<pii>(c, {INT_MAX, INT_MAX}));
    
    auto valid = [&](int x, int y) -> bool {
        return (x >= 0 && y >= 0 && x < r && y < c);
    };

    auto dist = [&](int x, int y, int i) -> int {
        int a = towers[i].first;
        int b = towers[i].second;
        return abs(x - a) + abs(y - b);
    };

    queue<array<int, 3>> q;

    rep(i, 0, n){
        int x, y; cin >> x >> y;
        --x; --y;
        towers[i] = {x, y};
        q.push({x, y, i});
    }

    while (!q.empty()){
        array<int, 3> f = q.front();
        int x = f[0], y = f[1], idx = f[2];
        q.pop();

        if (ans[x][y].second != INT_MAX){
            // already has been visited twice
            continue;
        }
        
        if (ans[x][y].first == idx) {
            // this tower already visited this place
            continue;
        }

        int d = dist(x, y, idx);
        if (ans[x][y].first == INT_MAX){
            // not visited yet
            ans[x][y].first = idx;
        } else {
            // visited once
            ans[x][y].second = idx;
        }

        for (pii dir : cardinal){
            int nx = x + dir.first;
            int ny = y + dir.second;
            if (!valid(nx, ny)) continue;
            if (ans[nx][ny].second != INT_MAX) continue;
            if (ans[nx][ny].first == idx) {
                // this tower already visited this place
                continue;
            }

            q.push({nx, ny, idx});
        }
    }

    rep(i, 0, r){
        rep(j, 0, c){
            cout << ans[i][j].first + 1 << " ";
        }
        cout << endl;
    }

    rep(i, 0, r){
        rep(j, 0, c){
            cout << ans[i][j].second + 1 << " ";
        }
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
}