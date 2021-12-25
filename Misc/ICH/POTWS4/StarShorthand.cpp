/** Code by 1egend **/
#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;

void solve(){
	string x;
	cin >> x;
	string ans;
	char current = x[0];
	int repeat = 1;
	for (int i = 1; i < x.length(); ++i){
		if (x[i] == current){
			repeat ++;
			continue;
		}

		if (repeat == 1){
			ans += current;
		}
		else{
			ans += current;
			ans += "*";
			ans += to_string(repeat);
			current = x[i];
			repeat = 1;
		}
	}
	cout << ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}	