/** Code by 1egend **/
// Problem: USACO 2016 February Contest, Bronze Problem 1. Milk Pails
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;

ifstream fin("pails.in");
ofstream fout("pails.out");

void solve(){
	int x, y, m;
	fin >> x >> y >> m;

	int maxX = floor(m * 1.0/x);
	// cout << maxX << endl;
	int ans = 0;
	for (int i = 0; i <= maxX; ++i){
		int remain = m - i * x;
		int total = m - (remain % y);

		ans = max<int>(ans, total);
	}

	fout << ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}	