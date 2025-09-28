/**
 * Solution by Charles Ran (polarity.sh)
 * Date: 2025-09-27
 * Contest: VJudge 751735
 * Problem: K
**/

#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

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

struct chash {
	// any random-ish large odd number will do
	const uint64_t C = ll(4e18*acos(0))+71;
    // random 32-bit number
	const uint32_t RANDOM = chrono::steady_clock::now().time_since_epoch().count();
	size_t operator()(uint64_t x) const {
		// see https://gcc.gnu.org/onlinedocs/gcc/Other-Builtins.html
		return __builtin_bswap64((x ^ RANDOM) * C);
	}
};
template <class K, class V> using cmap = unordered_map<K, V, chash>;
// example usage: cmap<int, int>

void solve(){
    int n, m; cin >> n >> m;

    vl power(n), curr(n);
    vector<vi> appliances(m);

    rep(i, 0, n){
        cin >> power[i];
        curr[i] = power[i];
    }

    int tot = 0;

    rep(i, 0, m){
        int c; cin >> c;
        tot += c;
        rep(j, 0, c){
            int x; cin >> x;
            x--;
            appliances[i].pb(x);
        }
    }

    vl sum(m, 0), sqsum(m, 0);
    int q; cin >> q;
    int rt = sqrt(q);

    vi good(m, -1);
    vector<vector<bool>> has;

    int gc = 0;

    int rtt = sqrt(tot);

    rep(i, 0, m){
        if (appliances[i].size() < rtt){
            continue;
        }

        good[i] = gc;

        has.pb(vector<bool>(n, false));

        for (int a : appliances[i]){
            has[gc][a] = true;
        }

        gc++;
    }

    vector<pair<int, ll>> changed;

    vi pr(n, -1);
    
    rep(i, 0, q){
        if (i == 0 || sz(changed) > rt){
            for (auto &[x, l] : changed){
                power[x] = l;
            }

            rep(j, 0, m){
                sum[j] = sqsum[j] = 0;
                for (int p : appliances[j]){
                    sum[j] += power[p];
                    sqsum[j] += power[p] * power[p];
                }
            }
            changed = {};
        }

        int c; cin >> c;
        if (c == 1){
            int x; ll l; cin >> x >> l;
            --x;
            curr[x] = l;
            changed.pb({x, l});
        } else {
            int j; cin >> j;
            --j;

            if (good[j] == -1){
                ll sm = 0, sqsm = 0;
                for (int p : appliances[j]){
                    sm += curr[p];
                    sqsm += curr[p] * curr[p];
                }
                cout << (sm * sm - sqsm)/2 << endl;
                continue;
            }

            ll sm = sum[j], sqsm = sqsum[j];
            for (auto &[x, l] : changed){
                if (has[good[j]][x]){
                    if (pr[x] == -1){
                        pr[x] = power[x];
                    }
                    sm -= pr[x];
                    sm += l;
                    sqsm -= pr[x] * pr[x];
                    sqsm += l * l;
                    pr[x] = l;
                }
            }

            for (auto &[x, l] : changed){
                pr[x] = -1;
            }

            cout << (sm * sm - sqsm)/2 << endl;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}