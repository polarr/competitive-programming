/** Code by 1egend **/
// Problem: CCC Problem S1 2020 Surmising a Sprinter's Speed	
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;

// ifstream fin(".in");
// ofstream fout(".out");

void solve(){
	double ans = 0.0;
	int n;
	cin >> n;
	vector <pair<double, double>> s;
	for (int i = 0; i< n; ++i){
		double a, b;
		cin >> a >> b;
		s.pb(make_pair(a, b));
	}
	sort(s.begin(), s.end());
	for (int i = 1; i < n; ++i){
		ans = max<double>(ans, abs(s[i].second - s[i - 1].second)/(s[i].first - s[i - 1].first));
	}
	cout << fixed << setprecision(5) << ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}	