/** Code by 1egend **/
// Problem: USACO 2016 US Open Contest, Bronze Problem 3. Field Reduction

#include <mingw32/bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;

ifstream fin("reduce.in");
ofstream fout("reduce.out");

void solve(){
	int x;
	fin >> x;

	// vector <pair<int, int>> pos;
	vector <int> xs;
	vector <int> ys;
	vector <pair<int, int>> ms;
	vector <pair<int, int>> ns;

	for (int i = 0; i < x; ++i){
		int a, b;
		fin >> a >> b;
		// pos.pb(make_pair(a, b));
		xs.pb(a);
		ys.pb(b);
		ms.pb(make_pair(a, i));
		ns.pb(make_pair(b, i));
	}

	vector <int> ks;

	sort(ms.begin(), ms.end());
	sort(ns.begin(), ns.end());

	ks.pb(ms[0].second); ks.pb(ms[x - 1].second); ks.pb(ns[x - 1].second); ks.pb(ns[0].second);

	ull ans = ULLONG_MAX;
	for (int i = 0; i < ks.size(); ++i){
		int k = ks[i];
		vector <int> as = xs;
		vector <int> bs = ys;
		as.erase(as.begin() + k);
		bs.erase(bs.begin() + k);

		sort(as.begin(), as.end());
		sort(bs.begin(), bs.end());

		ans = min<ull>(ans, (as[x - 2] - as[0])*(bs[x - 2] - bs[0]));
	}

	fout << ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}	