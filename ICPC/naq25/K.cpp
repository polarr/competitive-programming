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

int query(pii q){
    cout << "? " << q.first << " " << q.second << endl;
    int ans; cin >> ans;
    return ans;
}

void answer(pii q){
    cout << "! " << q.first << " " << q.second << endl;
}

void solve() {
    vector<pii> ask = {{2, 2}, {2, 4}, {4, 2}, {4, 4}};
    int idx = 3;
    rep(i, 0, 3){
        // ask first 3
        int ans = query(ask[i]);
        if (ans == 1){
            idx = i;
            break;
        }
    }

    auto [x, y] = ask[idx];
    int left = query({x, y - 1});

    if (left == 1){
        int up = query({x - 1, y - 1});
        if (up == 1){
            answer({x - 1, y - 1});
        } else {
            answer({x, y - 1});
        }
    } else {
        int up = query({x - 1, y});
        if (up == 1){
            answer({x - 1, y});
        } else {
            answer({x, y});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
}