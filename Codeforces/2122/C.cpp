/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-07-20
 * Contest: 
 * Problem: C
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
    vector<pii> pointsx;
    vector<pii> pointsy;
    rep(i, 0, n){
        int x, y; cin >> x >> y;
        pointsx.pb({x, i});
        pointsy.pb({y, i});
    }

    sort(all(pointsx));
    sort(all(pointsy));

    vector<vi> quads(4);
    vi label(n, 0);

    rep(i, n/2, n){
        label[pointsx[i].second] += 2;
        label[pointsy[i].second]++;
    }

    rep(i, 0, n){
        quads[label[i]].pb(i);
    }

    rep(i, 0, quads[0].size()){
        cout << quads[0][i] + 1 << " " << quads[3][i] + 1 << endl;
    }

    rep(i, 0, quads[1].size()){
        cout << quads[1][i] + 1 << " " << quads[2][i] + 1 << endl;
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