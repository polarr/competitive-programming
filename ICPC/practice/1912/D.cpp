/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-10-12
 * Contest: ICPC Practice Codeforces 1912
 * Problem: D
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e6 + 1;
const ll MOD = 1e9 + 7;

int max_div[MAX_N];

void solve(){
    int b, n; cin >> b >> n;
    if (gcd(b, n) != 1){
        int ans = 0;
        while (n != 1) {
            int prime = max_div[n];
            int count = 0;

            while (n % prime == 0) {
                count++;
                n /= prime;
            }

            if (b % prime != 0){
                cout << 0 << endl;
                return;
            }

            int countb = 0;
            while (b % prime == 0) {
                countb++;
                b /= prime;
            }

            ans = max(ans, (int) ceil(count * 1.0/countb));
        }

        cout << 1 << " " << ans << endl;
        return;
    }

    int k = 1;
    ll curr = b;
    while(k < n){
        if (curr % n == 1){
            cout << 2 << " " << k << endl;
            return;
        }
        if (curr % n == n - 1){
            cout << 3 << " " << k << endl;
            return;
        }
        k++;
        curr *= b;
        curr %= n;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    for (int i = 2; i < MAX_N; i++) {
		if (max_div[i] == 0) {
			for (int j = i; j < MAX_N; j += i) {
                max_div[j] = i;
            }
		}
	}

    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; ++t){
        // cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}