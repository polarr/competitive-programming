/** Code by 1egend **/
// Problem: USACO 2016 February Contest, Bronze Problem 2. Circular Barn

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;

ifstream fin("cbarn.in");
ofstream fout("cbarn.out");

void solve(){
	int x;
	fin >> x;

	vector <int> n;
	for (int i = 0; i < x; ++i){
		int t;
		fin >> t;
		n.pb(t);
	}

	int ans = INT_MAX;
	for (int i = 0; i < x; ++i){
		vector <int> c = n;
		rotate(c.begin(), c.begin() + i, c.end());

		int dis = 0;
		for (int z = 1; z < x; ++z){
			dis += c[z] * z;
		}

		ans = min<int>(dis, ans);
	}

	fout << ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}	