/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-12-02
 * Contest: 
 * Problem: 3224
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
    int n, k; cin >> n >> k;
    vi arr(n);
    rep(i, 0, n) {
        cin >> arr[i];
    }

    map<int, int> cnt;
    set<pii> s;
    rep(i, 0, k - 1) {
        int x = arr[i];
        s.erase({cnt[x], -x});
        cnt[x]++;
        s.insert({cnt[x], -x});
    }

    rep(i, k - 1, n) {
        int x = arr[i];
        s.erase({cnt[x], -x});
        cnt[x]++;
        s.insert({cnt[x], -x});
        int j = i - k;
        if (j >= 0) {
            int x = arr[j];
            s.erase({cnt[x], -x});
            cnt[x]--;
            s.insert({cnt[x], -x});
        }

        auto it = prev(s.end());

        cout << -((*it).second) << " ";
    }
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}