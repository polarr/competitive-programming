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

ll mod_exp(ll x, ll n, ll m) {
	x %= m;
	ll ans = 1;
	while (n > 0) {
		if (n % 2 == 1) {
            ans = ans * x % MOD;
        }
        x = x * x % MOD;
		n /= 2;
	}

	return ans;
}

void solve(){
    int n, d; cin >> n >> d;

    vector<array<ll, 3>> dp(n);
    vector<bool> coach(n);
    vi pos(n);

    rep(i, 0, n) {
        cin >> pos[i];
        
        int c; cin >> c;
        coach[i] = c;
    }

    dp[0][2] = coach[0];
    dp[0][1] = 0;
    dp[0][0] = 1 + dp[0][1] + dp[0][2];

    int l = 0, r = 0;
    ll pow = 0, mult = 0;

    // cout << dp[0][0] << endl;

    rep(i, 1, n) {
        int p = pos[i];
        while (r < i) {
            if (coach[r]) {
                mult += dp[r][2];
                mult %= MOD;
            } else {
                pow++;
                mult *= 2;
                mult %= MOD;
            }
            
            r++;
        }

        while (pos[l] < p - d) {
            if (coach[l]) {
                mult += MOD - (dp[l][2] * mod_exp(2, pow, MOD) % MOD);
                mult %= MOD;
            } else {
                pow--;
            }

            l++;
        }

        dp[i][0] = dp[i - 1][0];
        dp[i][1] = dp[i][2] = 0;
        if (coach[i]) {
            dp[i][2] = dp[i - 1][0];
        } else {
            dp[i][1] = mult;
        }

        dp[i][0] += dp[i][1];
        dp[i][0] %= MOD;
        dp[i][0] += dp[i][2];
        dp[i][0] %= MOD;

        // cout << dp[i][0] << endl;
    }

    ll ans = dp[n - 1][0];
    ans += MOD - 1;
    ans %= MOD;

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}