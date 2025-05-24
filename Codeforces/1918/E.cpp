/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-05-23
 * Contest: 
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

// Found both the randomized and nonrandomized solutions in time but couldn't implement in time

int query(int i){
    cout << "? " << i << endl;
    char res; cin >> res;
    if (res == '>'){
        return -1;
    } else if (res == '<'){
        return 1;
    }

    return 0;
}

void solve(){
    int n; cin >> n;

    vi ans(n);

    while (query(1) != 0){
    }



    function<vector<int>&, int, int>> r;
    r = [&](vector<int>& idx, int lo, int hi){

    };

    vector<int> a;
    rep(i, 1, n + 1){
        a.pb(i);
    }

    r(a, 1, n);
    cout << "!";
    rep(i, 0, n){
        cout << " " << ans[i];
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