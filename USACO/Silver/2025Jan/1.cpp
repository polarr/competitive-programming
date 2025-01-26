/**
 * Solution by 1egend (polarity.sh)
 * Date: 2025-01-24
 * Contest: USACO 2025 January Silver
 * Problem: 1
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
    ll n; cin >> n;
    vl a(n), b(n);
    vector<priority_queue<ll>> color(n + 1, priority_queue<ll>{});

    ll ans = 0;

    rep(i, 0, n){
        cin >> a[i];
    }
    rep(i, 0, n){
        cin >> b[i];
    }

    for (ll i = 0; i < n; i++){
        if (a[i] == b[i]){
            ans += i * (i - 1)/2 + i;
            ans += (n - i - 1) * (n - i - 2)/2 + n - i - 1;
        }
    }

    // cout << ans << endl;

    vl sum(n + 1, 0), count(n + 1, 0);

    rep(i, 0, n){
        ll before = n - i;
        int c = a[i];
        sum[c] += (ll)(i + 1);
        color[c].push((ll)(i + 1));

        int cc = b[i];
        while(!color[cc].empty()){
            if (color[cc].top() < before){
                break;
            }

            sum[cc] -= color[cc].top();
            color[cc].pop();
            count[cc]++;
        }

        // cout << count[cc] << " " << before << " " << sum[cc] << endl;

        ans += count[cc] * before + sum[cc];
    }

    sum = vl(n + 1, 0), count = vl(n + 1, 0), color = vector<priority_queue<ll>>(n + 1, priority_queue<ll>{});

    for (int i = n - 1; i >= 0; i--){
        ll after = i + 1;

        int cc = b[i];
        while(!color[cc].empty()){
            if (color[cc].top() < after){
                break;
            }

            sum[cc] -= color[cc].top();
            color[cc].pop();
            count[cc]++;
        }

        ans += count[cc] * after + sum[cc];

        int c = a[i];
        sum[c] += (ll)(n - i);
        color[c].push((ll)(n - i));
    }

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}