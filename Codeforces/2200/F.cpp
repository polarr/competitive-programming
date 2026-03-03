/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2026-03-02
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

void solve(){
    int n, m; cin >> n >> m;

    using T = pair<int, ll>;
    vector<T> arr(n);

    rep(i, 0, n) {
        int x; ll y; cin >> y >> x;
        arr[i] = {x, y};
    }

    sort(all(arr));

    vl ans(n + 1, 0);
    multiset<ll> curr;
    rep(i, 0, n) {
        curr.insert(0);
    }

    ll sum = 0;
    int j = n;
    for (int use = n; use >= 1; use--) {
        while (j > 0 && arr[j - 1].first >= use - 1) {
            j--;
            ll x = arr[j].second;
            auto b = curr.begin();
            if (x > *b) {
                sum -= *b;
                sum += x;
                curr.erase(b);
                curr.insert(x);
            }
        }

        while (sz(curr) > use) {
            auto b = curr.begin();
            sum -= *b;
            curr.erase(b);
        }

        ans[use] = sum;
    }

    vl mx(n + 1, 0);
    rep(i, 1, n + 1) {
        mx[i] = max(mx[i - 1], ans[i]);
    }

    vl ans2(n + 1, 0);
    curr = {};
    rep(i, 0, n) {
        curr.insert(0);
    }

    sum = 0;
    j = n;
    for (int use = n; use >= 1; use--) {
        while (j > 0 && arr[j - 1].first >= use) {
            j--;
            ll x = arr[j].second;
            auto b = curr.begin();
            if (x > *b) {
                sum -= *b;
                sum += x;
                curr.erase(b);
                curr.insert(x);
            }
        }

        while (sz(curr) > use) {
            auto b = curr.begin();
            sum -= *b;
            curr.erase(b);
        }

        ans2[use] = sum;
    }

    vl mx2(n + 1, 0);
    rep(i, 1, n + 1) {
        mx2[i] = max(mx2[i - 1], ans2[i]);
    }

    rep(i, 0, m) {
        int x; ll y; cin >> y >> x;

        ll a = mx[n];
        ll b = y + mx2[x];

        cout << max(a, b) << " ";
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