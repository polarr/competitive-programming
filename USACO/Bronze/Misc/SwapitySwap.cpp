/** Code by 1egend **/
// Problem: 
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;

ifstream fin("swap.in");
ofstream fout("swap.out");

void solve(){
	int n, k;
	fin >> n >> k;
	vector <int> cows;
	vector <int> m;
	for (int i = 1; i <= n; ++i){
		cows.pb(i);
		m.pb(i);
	}
	int a1, a2, b1, b2;
	fin >> a1 >> a2 >> b1 >> b2;
	int cycle = 0;
	if (a2 < b1 || b2 < a1){
		cycle = 2;
	}
	if (cycle == 0){
		for (int i = 0; i < k; ++i){
			if (i > 0 && cows == m){
				cycle = i;
				break;
			}
			reverse(cows.begin() + a1 - 1, cows.begin() + a2);
			reverse(cows.begin() + b1 - 1, cows.begin() + b2);
		}
	}
	if (cycle > 0){
		cows = m;
		for (int i = 0; i < (k % cycle); ++i){
			reverse(cows.begin() + a1 - 1, cows.begin() + a2);
			reverse(cows.begin() + b1 - 1, cows.begin() + b2);
		}
	}
	for (int i = 0; i < n; ++i){
		fout << cows[i] << endl;
	}
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
  	return 0;
}