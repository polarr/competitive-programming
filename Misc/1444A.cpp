/** Code by 1egend **/
#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;

void solve(){
	ull x, y;
	cin >> x >> y;
	if (y > x){
		cout << x << endl;
		return;
	}
	if (x == y){
		for (ull i = 2; i < x; ++i){
			if (i % 2 == 0){
				cout << x/i << endl;
				return;
			}
		}
	}
	if (x > y){
		if (x % y != 0){
			cout << x << endl;
			return;
		}
		
		
	}
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        // cout << "Case #" << t  << ": " << endl;
        solve();
    }
    return 0;
}	