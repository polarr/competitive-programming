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
    int q; cin >> q;

    deque<ll> d;
    bool f = true;

    ll ans = 0;
    ll n = 0;
    ll sum = 0;
    ll pre = 0;
    rep(i, 0, q){
        int s; cin >> s;
        if (s == 1){
            ll last = d.front();
            if (!f){
                last = d.back();
            }
            ans += pre;
            ans -= (n - 1) * last;
            pre += last;
            if (f){
                d.pop_front();
                d.push_back(last);
                last = d.front();
                pre -= last;
            } else {
                d.pop_back();
                d.push_front(last);
                last = d.back();
                pre -= last;
            }
        } else if (s == 2){
            ans = (n + 1) * sum - ans;
            ll first = d.back();
            if (!f){
                first = d.front();
            }
            f = !f;
            pre = sum - first;
        } else {
            ll k; cin >> k;
            if (f){
                d.push_front(k);
            } else {
                d.push_back(k);
            }

            n++;
            ans += n * k;
            pre = sum;
            sum += k;
        }

        cout << ans << endl;
    }
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