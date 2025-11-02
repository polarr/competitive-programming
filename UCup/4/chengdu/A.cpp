#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
#define pb push_back
#define rep(i, a, b) for (int i = (a); i < (b); ++i)

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    vl b(n);
    ll mult = 1e6;
    ll gap = mult * (sum - 100);
    ll add = 499999;
    ll sub = 500000;
    rep(i, 0, n){
        b[i] = mult * a[i];
        if (gap >= 0 && b[i] == 0) continue;
        if (gap >= 0){
            b[i] -= min(sub, gap);
            gap -= min(sub, gap);
        } else {
            b[i] += min(add, -gap);
            gap += min(add, -gap);
        }
    }

    if (gap != 0){
        cout << "No" << endl;
        return;
    }

    cout << "Yes" << endl;
    rep(i, 0, n){
        cout << b[i] << " ";
    }

    cout << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int test;
    cin >> test;
    while (test--) {
        solve();
    }
}