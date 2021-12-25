/** Code by 1egend **/
// Problem: CCC 2021 S1 Crazy Fencing
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;

// ifstream fin(".in");
// ofstream fout(".out");

void solve(){
	int x;
	cin >> x;
	vector <int> n;
	vector <int> m  = {0};
	for (int i = 0; i < x + 1; ++i){
		int a;
		cin >> a;
		n.pb(a);
	}
	for (int i = 0; i < x; ++i){
		int b;
		cin >> b;
		m.pb(b);
	}
	double ans = 0;
	for (int i = 1; i < x + 1; ++i){
		int j = n[i - 1];
		int k = n[i];
		int w = m[i];
		ans += w * (j + k);
	}
	cout << fixed << setprecision(1) << ans/2.0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}	