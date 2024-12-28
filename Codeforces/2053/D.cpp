/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-12-28
 * Contest: Codeforces 2053
 * Problem: D
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 998244353;

ll mod_exp(ll x, ll n, ll m) {
	x %= m;

	ll res = 1;
	while (n > 0) {
		if (n % 2 == 1) { res = res * x % m; }
		x = x * x % m;
		n /= 2;
	}

	return res;
}

void solve(){
    int n, q; cin >> n >> q;

    vector<int> arr(n);
    vector<pair<int, int>> sorta(n);
    vector<pair<int, int>> sortb(n);
    vector<int> brr(n);
    vector<int> reala(n);
    vector<int> realb(n);

    for (int i = 0; i < n; i++){
        cin >> arr[i];
        sorta[i] = {arr[i], i};
    }

    for (int i = 0; i < n; i++){
        cin >> brr[i];
        sortb[i] = {brr[i], i};
    }

    ll ans = 1;

    sort(sorta.begin(), sorta.end());
    sort(sortb.begin(), sortb.end());

    for (int i = 0; i < n; i++){
        reala[sorta[i].second] = i;
        realb[sortb[i].second] = i;

        ans *= min(sorta[i].first, sortb[i].first);
        ans %= MOD;
    }

    auto findnext = [&](int o, int i){
        if (o == 1){
            int curr = sorta[i].first;
            int l = i, r = n - 1;
            while (l < r){
                int mid = l + (r - l + 1)/2;

                if (sorta[mid].first == curr){
                    l = mid;
                }
                else {
                    r = mid - 1;
                }
            }

            return l;
        }

        int curr = sortb[i].first;
        int l = i, r = n - 1;
        while (l < r){
            int mid = l + (r - l + 1)/2;

            if (sortb[mid].first == curr){
                l = mid;
            }
            else {
                r = mid - 1;
            }
        }

        return l;
    };

    cout << ans << " ";

    for (int i = 0; i < q; i++){
        int o, x; cin >> o >> x;
        --x;
        if (o == 1){
            // re-sort a
            int ra = reala[x];
            int nx = findnext(o, ra);

            ans *= mod_exp(min(sorta[ra].first, sortb[ra].first), MOD - 2, MOD);
            ans %= MOD;

            if (ra != nx){
                
                ans *= mod_exp(min(sorta[nx].first, sortb[nx].first), MOD - 2, MOD);
                ans %= MOD;

            }

            reala[sorta[ra].second] = nx;
            reala[sorta[nx].second] = ra;

            pair<int, int> temp = sorta[ra];
            sorta[ra] = sorta[nx];
            sorta[nx] = {temp.first + 1, temp.second};

            ans *= min(sorta[ra].first, sortb[ra].first);
            ans %= MOD;

            if (ra != nx){
                ans *= min(sorta[nx].first, sortb[nx].first);
                ans %= MOD;
            }

            cout << ans << " ";
            //cout << ra << nx << endl;
            continue;
        }

        // re-sort a
        int rb = realb[x];
        int nx = findnext(o, rb);

        ans *= mod_exp(min(sorta[rb].first, sortb[rb].first), MOD - 2, MOD);
        ans %= MOD;

        if (rb != nx){
            ans *= mod_exp(min(sorta[nx].first, sortb[nx].first), MOD - 2, MOD);
            ans %= MOD;
        }
        

        realb[sortb[rb].second] = nx;
        realb[sortb[nx].second] = rb;

        pair<int, int> temp = sortb[rb];
        sortb[rb] = sortb[nx];
        sortb[nx] = {temp.first + 1, temp.second};

        ans *= min(sorta[rb].first, sortb[rb].first);
        ans %= MOD;

        if (rb != nx){
            ans *= min(sorta[nx].first, sortb[nx].first);
            ans %= MOD;
        }
        

        cout << ans << " ";
        //cout << rb << nx << endl;
    }

    cout << endl;
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