#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using pii = pair<int, int>;
#define pb push_back
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    ll k, n; cin >> k >> n;

    ll share = 0;
    vl weights(n);
    rep(i, 0, n) {
        cin >> weights[i];
        share += weights[i];
    }

    if (share % k != 0){
        cout << "NO" << endl;
        return;
    }

    share /= k;

    vi to(n, -1);

    ll at = 0;
    ll sum = weights[n - 1];
    rep(i, 0, n){
        int last = (i + n - 1) % n;
        sum -= weights[last];
        while (sum < share){
            sum += weights[at];
            at = (at + 1) % n;
        }

        if (sum == share){
            to[i] = at;
        }
    }

    vector<bool> visited(n, false);
    rep(i, 0, n){
        if (visited[i]) continue;
        int curr = i;
        ll len = 0;
        while (true){
            visited[curr] = true;
            len++;
            curr = to[curr];
            if (curr == -1){
                break;
            }
            if (curr == i){
                if (len == k){
                    cout << "YES" << endl;
                    return;
                }
                break;
            }
            if (visited[curr]) break;
        }
    }

    cout << "NO" << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}