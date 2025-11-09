#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
#define rep(i, a, b) for(ll i = (a); i < (b); ++i)
#define pb push_back

void solve(){
    ll n, k, d, s; cin >> n >> k >> d >> s;

    k %= n;

    ll mn = n/(k == 0 ? n  : __gcd(n, k));

    ll mult = d/mn;
    ll rem = d % mn;

    vl arr(n);
    rep(i, 0, n) cin >> arr[i];

    vl col(n, 0);
    vector<bool> visited(n, false);
    rep(i, 0, n){
        if (visited[i]) continue;

        visited[i] = true;
        ll sum = 0;
        if (mult > 0){
            rep(j, 0, mn){
                ll at = (i + j * k) % n;
                sum += arr[at];
            }

            sum *= mult;
        }

        rep(j, 0, rem){
            ll at = (i + j * k) % n;
            sum += arr[at];
        }

        col[i] = sum;
        ll cyc = mult > 0 ? mn : rem;
        rep(j, 1, cyc){
            ll at = (i + j * k) % n;
            ll pr = (i + (j - 1) * k) % n;
            ll nx = (i + (j + rem - 1) * k) % n;

            sum -= arr[pr];
            sum += arr[nx];

            col[at] = sum;
            visited[at] = true;
        }
    }

    vector<bool> possible(n, false);
    visited = vector<bool>(n, false);

    auto good = [&](int i) -> int {
        return (i <= n - s ? 1 : 0);
    };

    rep(i, 0, n){
        if (visited[i]) continue;

        visited[i] = true;

        if (mn <= n - d + 1){
            int cnt = 0;
            rep(j, 0, mn){
                ll at = (i + (n - j) * k) % n;
                cnt += good(at);
            }

            rep(j, 0, mn){
                ll at = (i + (n - j) * k) % n;
                visited[at] = true;
                if (cnt > 0) {
                    possible[at] = true;
                }
            }

            continue;
        }

        int cnt = 0;
        rep(j, 0, n - d + 1){
            ll at = (i + (n - j) * k) % n;
            cnt += good(at);
        }

        if (cnt > 0){
            possible[i] = true;
        }

        rep(j, 1, n - d + 1){
            ll at = (i + (n - j) * k) % n;
            ll pr = (i + (n - j + 1) * k) % n;
            ll nx = (i + (n - j + d) * k) % n;

            cnt += good(nx);
            cnt -= good(pr);

            if (cnt > 0) possible[at] = true;
            visited[at] = true;
        }
    }

    ll ans = -1e18;
    ll curr = 0;
    rep(i, 0, s){
        curr += col[i];
    }

    // rep(i, 0, n) cout << col[i] << endl;

    ans = max(ans, curr);
    rep(i, 1, n){
        int pr = i - 1;
        int nx = (i + s - 1) % n;
        curr -= col[pr];
        curr += col[nx];

        if (possible[i]){
            ans = max(ans, curr);
        }
    }

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}