/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-05-08
 * Contest: CSES Problemset
 * Problem: 1191
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
    int n; ll k; cin >> n >> k;

    vl a(n);
    ll s = 0;
    rep(i, 0, n){
        cin >> a[i];
        s += a[i];
    }

    if (s <= k){
        cout << 1 << endl;
        return;
    }

    int lg = log2(n) + 1;

    vector<vector<pair<int, ll>>> jump(n, vector<pair<int, ll>>(lg));

    ll sum = 0;
    int j = 0;

    rep(i, 0, n){
        if (i != 0) sum -= a[i - 1];
        while (sum + a[j] <= k){
            sum += a[j];
            j++;
            j %= n;
        }

        jump[i][0] = {j, (j <= i ? j + n - i : j - i)};
    }

    rep(i, 1, lg){
        rep(j, 0, n){
            pair<int, ll> a = jump[j][i - 1];
            jump[j][i] = {jump[a.first][i - 1].first, jump[a.first][i - 1].second + a.second};
        }
    }

    int ans = n;

    rep(i, 0, n){
        int pos = i;
        int rem = n;
        int can = 0;

        while(rem > 0){
            bool found = false;
            for (int j = lg - 1; j >= 0; j--){
                if (jump[pos][j].second <= rem){
                    rem -= jump[pos][j].second;
                    pos = jump[pos][j].first;
                    can += (1 << j);

                    found = true;
                    break;
                }
            }

            if (found) continue;

            can++;
            break;
        }

        ans = min(ans, can);
    }

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}