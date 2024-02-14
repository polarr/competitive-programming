/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-02-01
 * Contest: Happy Hackers Programming Challenge 1
 * Problem: P4 - Yet another A + B problem
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e7 + 1;
const ll MOD = 1e9 + 7;

int max_div[MAX_N];

void solve(){
    int c; 
    cin >> c;

    ull ans = 1;
    while (c != 1) {
        int prime = max_div[c];
        int count = 0;

        while (c % prime == 0) {
            count++;
            c /= prime;
        }

        ans *= (2 * count + 1);
    }

    cout << ans << endl;
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