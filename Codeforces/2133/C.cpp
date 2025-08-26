/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-08-25
 * Contest: Codeforces 2133
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

int query(vi a, int x){
    cout << "? " << x << " " << a.size();
    for (int el : a){
        cout << " " << el;
    }

    cout << endl;
    int ans; cin >> ans;
    return ans;
}

void solve(){
    int n; cin >> n;

    vi every(n);
    rep(i, 0, n){
        every[i] = i + 1;
    }

    vector<vi> layers(n);
    int j = 0;
    vi ans;

    rep(i, 0, n){
        int q = query(every, i + 1) - 1;
        layers[q].pb(i + 1);
        j = max(j, q);
    }

    int curr = layers[j][0];
    ans.pb(curr);
    while (j != 0){
        for (int el : layers[j - 1]){
            int q = query({curr, el}, curr);
            if (q == 1) continue;
            curr = el;
            ans.pb(curr);
            j--;
            break;
        }
    }

    cout << "! " << ans.size();
    rep(i, 0, ans.size()){
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