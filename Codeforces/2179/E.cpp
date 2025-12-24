/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-12-23
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

void solve(){
    int n, x, y; cin >> n >> x >> y;

    string s; cin >> s;
    vi arr(n);
    rep(i, 0, n) {
        arr[i] = s[i] - '0';
    }

    ll sum = 0;
    vl p(n);
    rep(i, 0, n) {
        cin >> p[i];
        sum += p[i];
    }

    if (x > y) {
        swap(x, y);
        rep(i, 0, n) {
            arr[i] = 1 - arr[i];
        }
    }

    bool foundx = false, foundy = false;
    rep(i, 0, n) {
        if (arr[i] == 1) {
            foundy = true;
        } else {
            foundx = true;
        }
    }

    if (!foundy) {
        cout << "NO" << endl;
        return;
    }

    if (x + y < sum) {
        cout << "NO" << endl;
        return;
    }

    vector<pair<ll, ll>> assign(n);
    ll rx = 0, ry = 0;
    rep(i, 0, n) {
        if (arr[i] == 0) {
            assign[i] = {p[i]/2 + 1, p[i] - (p[i]/2 + 1)};
            rx += p[i]/2 + 1;
            ry += p[i] - (p[i]/2 + 1);
        } else {
            assign[i] = {0, p[i]};
            ry += p[i];
        }
    }

    if (rx > x) {
        cout << "NO" << endl;
        return;
    }

    ll diff = x + y - sum;
    rep(i, 0, n) {
        if (arr[i] == 0) {
            ry += diff;
            assign[i].second += diff;
            break;
        }

        if (!foundx && (p[i] % 2 == 1 || i == n - 1)) {
            ry += diff;
            assign[i].second += diff;
            break;
        }
    }

    rep(i, 0, n) {
        ll need = x - rx;
        if (arr[i] == 1) {
            ll rem = assign[i].first + assign[i].second;
            rem = assign[i].second - (rem/2 + 1);
            rx += min(need, rem);
            assign[i].first += min(need, rem);
            assign[i].second -= min(need, rem);
        } else {
            ll rem = assign[i].second;
            rx += min(need, rem);
            assign[i].first += min(need, rem);
            assign[i].second -= min(need, rem);
        }
    }

    if (rx != x) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
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