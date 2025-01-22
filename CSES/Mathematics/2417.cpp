/**
 * Solution by 1egend (polarity.sh)
 * Date: 2025-01-21
 * Contest: 
 * Problem: 2417
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e6;
const ll MOD = 1e9 + 7;

vector<int> max_div(MAX_N + 1);
void prime_sieve() {
    for (int i = 2; i <= MAX_N; i++) {
        if (max_div[i] == 0) {
            for (int j = i; j <= MAX_N; j += i) { max_div[j] = i; }
        }
    }
}

vector<int> factor(int n){
    vector<int> ans;
	while(n != 1){
        int i = max_div[n];
		while (n % i == 0) {
			n /= i;
		}

        ans.pb(i);
	}

	return ans;
}

void solve(){
    prime_sieve();
    vector<ll> d(MAX_N + 1, 0);
    ll n; cin >> n;
    for (int s = 0; s < n; s++){
        int x; cin >> x;
        vector<int> f = factor(x);
        int fs = f.size();

        for (int i = 0; i < pow(2, fs); i++){
            int dd = 1;
            for (int j = 0; j < fs; j++){
                bool toggled = i & (1 << j);
                if (toggled){
                    dd *= f[j];
                }
            }

            d[dd]++;
        }
    }

    ll ans = n * (n - 1)/2;
    
    for (int i = 2; i < MAX_N + 1; i++){
        if (d[i] == 0 || d[i] == 1){
            continue;
        }
        // cout << d[i] << endl;
        ll pairs = d[i] * (d[i] - 1)/2;
        ll x = i;
        bool par = true;
        while (x != 1){
            ll p = max_div[x];
            while (x % p == 0){
                x /= p;
            }
            par = !par;
        }

        if (par){
            ans += pairs;
        } else {
            ans -= pairs;
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