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

// 0 = right, 1 = top, 2 = left, 3 = down
vector<pii> cardinal = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};

void solve() {
    int r, c; cin >> r >> c;

    int x, y; cin >> x >> y;
    int a, b; cin >> a >> b;

    vector<vi> maze(r + 2, vi(c + 2, 1));
    rep(i, 1, r + 1){
        string s; cin >> s;
        rep(j, 1, c + 1){
            int x = s[j - 1] - '0';

            maze[i][j] = x;
        }
    }

    array<bool, 4> noneVisited = {false, false, false, false};

    vector<vector<array<bool, 4>>> visited(r + 2, vector<array<bool, 4>>(c + 2, noneVisited));

    int dir = 0;

    auto move = [&](int idx) -> pii {
        int dx = cardinal[idx].first;
        int dy = cardinal[idx].second;
        return {x + dx, y + dy};
    };

    auto good = [&](pii coord) -> bool {
        return maze[coord.first][coord.second] == 0;
    };

    while (!visited[x][y][dir]){
        visited[x][y][dir] = true;

        if (x == a && y == b){
            cout << 1 << endl;
            return;
        }

        int dirLeft = (dir + 1) % 4;
        pii place = move(dirLeft);

        if (good(place)){
            x = place.first;
            y = place.second;
            dir = dirLeft;
            continue;
        }

        place = move(dir);
        if (good(place)){
            x = place.first;
            y = place.second;
            continue;
        }

        dir = (dir + 3) % 4;
    }

    cout << 0 << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
}