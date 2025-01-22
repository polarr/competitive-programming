/**
 * Solution by 1egend (polarity.sh)
 * Date: 2025-01-20
 * Contest: DMOJ yac9
 * Problem: 3
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

vector<pair<int, int>> factor(int n, vector<int>& k){
    int kk = 1;
	vector<pair<int, int>> ans;
	while(n != 1){
        int i = max_div[n];
        int a = 0;
		while (n % i == 0) {
            a++;
			n /= i;
		}

        k.pb(kk);
        ans.pb({i, a});
        kk *= a + 1;
	}
    k.pb(kk);
	return ans;
}


void solve(){
    prime_sieve();
    int n; cin >> n;
    vector<int> b(n);
    vector<int> dp(MAX_N + 1, INT_MAX);

    dp[1] = 0;

    ll s = 0;

    for (int i = 0; i < n; i++){
        int c = 0;

        int a; cin >> a;

        // while(a != 1){
        //     int p = max_div[a];
        //     int e = 0;
        //     while(a % p == 0){
        //         a /= p;
        //         e++;
        //     }

        //     // p^e
        //     int m = 0;
        //     int ee = 0;
        //     for (int j = p; j <= e * p; j+= p){
        //         int jj = j;
        //         while (jj % p == 0){
        //             jj /= p;
        //             ee++;
        //         }

        //         if (ee >= e){
        //             m = j;
        //             break;
        //         }
        //     }
        //     c = max(c, m);
        // }

        b[i] = max_div[a];

        // cout << b[i] << " ";
        b[i] -= i + 1;
    }

    // cout << endl;

    ll ans = 0;
    
    stack<pair<int, int>> needs;

    for (int i = n - 1; i >= 0; i--){
        needs.push({b[i], i});

        int k = n;
        while(!needs.empty()){
            pair<int, int> t = needs.top();
            if (t.first > -i){
                k = t.second;
                break;
            }

            needs.pop();
        }

        ans += (ll)(k - i);
    }

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}