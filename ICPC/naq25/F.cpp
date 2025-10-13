#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using ld = long double;
#define pb push_back
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve() {
    int n, k; cin >> n >> k;

    vector<ld> arr(n);
    rep(i, 0, n) cin >> arr[i];
    sort(all(arr));

    ld sqsum = 0;
    ld sum = 0;
    ld kk = k;

    // take consecutive intervals
    rep(i, 0, k){
        sqsum += arr[i] * arr[i];
        sum += arr[i];
    }

    ld mean = sum / kk;

    ld ans = sqsum + kk * mean * mean - sum * mean * (ld) 2;

    rep(i, 1, n - k + 1){
        int p = i - 1;
        int q = i + k - 1;

        sqsum -= arr[p] * arr[p];
        sqsum += arr[q] * arr[q];

        sum -= arr[p];
        sum += arr[q];

        mean = sum / kk;

        ans = min(ans, sqsum + kk * mean * mean - sum * mean * (ld) 2);
    }

    cout << fixed << setprecision(20) << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
}