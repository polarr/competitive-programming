/** Code by 1egend **/
#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;

ull ans = 0;
void solve(ull n, ull m){
	while (n > 0){
		ull x = ceill(m/(n * 1.0));
		//cout << x << endl;
		ans += x;
		n = n * x - m;
		m *= x;
	}
	cout << ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	if (n == 1){
		cout << m;
		return 0;
	}
    solve(n, m);
    return 0;
}	