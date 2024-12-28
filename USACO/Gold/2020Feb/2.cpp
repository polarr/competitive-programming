/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-12-27
 * Contest: USACO 2020 Feb Gold
 * Problem: 2
**/

#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

const string iofilename = "help";
ifstream fin(iofilename + ".in");
ofstream fout(iofilename + ".out");

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

// Use fstream (fin, fout) instead of iostream!
void solve(){
    int n; fin >> n;

    vector<int> add(2 * n, 0);
    vector<int> sub(2 * n, 0);
    for (int i = 0; i < n; i++){
        int l, r; fin >> l >> r;

        --l; --r;

        add[l]++;
        sub[r]++;
    }

    int curr = 0;
    ll ans = 0;

    for (int i = 0; i < 2 * n; i++){
        if (add[i] != 0){
            ans += mod_exp(2, n - curr - 1, MOD);
            ans %= MOD;
        }

        curr += add[i];
        curr -= sub[i];
    }

    fout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    solve();
    return 0;
}