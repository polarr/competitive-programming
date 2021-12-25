/** Code by 1egend **/
#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;

void solve(){
	vector <int> rooms;
	int n;
	cin >> n;
	ull sum = 0;
	for (int i = 0; i < n; ++i){
		int t;
		cin >> t;
		sum += t;
		rooms.push_back(t);
	}
	ull ans = 0;
	ull total = 0;
	for (int i = 0; i < n - 1; ++i){
		total += rooms[i];
		ans += rooms[i] * (sum - total);
	}
	cout << ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}	