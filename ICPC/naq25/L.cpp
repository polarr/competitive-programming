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

void solve() {
    int n; cin >> n;
    vi arr(n);
    rep(i, 0, n) cin >> arr[i];
    int a = arr[0]/3;
    int c = arr[n - 1]/3;
    int b = arr[1] - 2 * a;

    cout << a << " " << b << " " << c << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
}