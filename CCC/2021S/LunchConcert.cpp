/** Code by 1egend **/
// Problem: CCC S3 2021 Lunch Concert
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;

// ifstream fin(".in");
// ofstream fout(".out");

void solve(){
	int n;
	cin >> n;
	vector<tuple<int, int, int>> x;
	int mn = 1e9, mx = 0;
	for (int i = 0; i < n; ++i){
		int p, w, d;
		cin >> p >> w >> d;
		x.pb(make_tuple(p, w, d));
		mn = min<int>(mn, p + d);
		mx = max<int>(mx, p - d);
	}
	//cout << mn << " " << mx << endl;
	if (mn >= mx){
		cout << 0;
		return;
	}
	vector<ull> pos(mx - mn + 1, 0);
	for (int i = 0; i < n; ++i){
		tuple<int, int, int> pt= x[i];
		int a = get<0>(pt), b = get<1>(pt), c = get<2>(pt);
		int s = a - c;
		int l = a + c;
		//cout << s << " " << l << endl;
		for (int k = mn; k < s; ++k){
			pos[k - mn] += (s - k) * b;
		}
		for (int k = l + 1; k <= mx; ++k){
			pos[k - mn] += (k - l) * b;
		}
	}
	ull ans = ULLONG_MAX;
	for (int i = 0; i < mx - mn + 1; ++i){
		//cout << pos[i] << " ";
		ans = min<ull>(ans, pos[i]);
	}
	cout << ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}	