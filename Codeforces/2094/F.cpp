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
    int n, m, k; cin >> n >> m >> k;

    ll a = 0;
    rep(i, 1, k + 1){
        if ((k % i == 0) && (n % i == 0) && (m % (k/i) == 0)){
            a = i;
            break;
        }
    }

    ll b = k/a;

    rep(i, 0, n){
        rep(j, 0, m){
            ll ii = i % a;
            ll jj = j % b;
            ll v = jj + ii * b + 1;
            if (a == 1 && i % 2 == 1){
                v = b + 1 - v;
                if (b % 2 == 1 && v == (b + 1)/2){
                    v--;
                }
                else if (b % 2 == 1 && v == (b + 1)/2 - 1){
                    v++;
                }
            }
            if (b == 1 && j % 2 == 1){
                v = a + 1 - v;
                if (a % 2 == 1 && v == (a + 1)/2){
                    v--;
                }
                else if (a % 2 == 1 && v == (a + 1)/2 - 1){
                    v++;
                }
            }
            cout << v << " ";
        }

        cout << endl;
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