/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-09-24
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
    int n; ll w; cin >> n >> w;
    ll half = (w + 1)/2;
    vector<pair<ll, ll>> weights(n);
    rep(i, 0, n){
        ll k; cin >> k;
        weights[i] = {k, i + 1};
    }

    rep(i, 0, n){
        if (weights[i].first >= half && weights[i].first <= w){
            cout << 1 << endl;
            cout << weights[i].second << endl;
            return;
        }
    }

    sort(all(weights));
    ll sum = 0;
    int j = -1;
    rep(i, 0, n){
        sum += weights[i].first;
        if (sum > w){
            cout << -1 << endl;
            return;
        }
        if (sum >= half){
            j = i;
            break;
        }
    }

    if (j == -1){
        cout << -1 << endl;
        return;
    }

    cout << j + 1 << endl;
    rep(i, 0, j + 1){
        cout << weights[i].second << " ";
    }
    cout << endl;
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