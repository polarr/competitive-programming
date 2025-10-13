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
    int n, k; cin >> n >> k;
    vi arr(n);
    rep(i, 0, n) cin >> arr[i];

    sort(all(arr));
    int distinct = 0;
    rep(i, 0, n){
        if (i == 0 || arr[i] != arr[i - 1]){
            distinct++;
        }
    }

    cout << min(distinct, k) << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
}