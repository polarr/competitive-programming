/** Code by 1egend **/
// Problem: 
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;

ifstream fin("cowsignal.in");
ofstream fout("cowsignal.out");

void solve(){
	int m, n, k;
	fin >> m >> n >> k;
	vector <string> signal;
	for (int i = 0; i < m; ++i){
		string t;
		fin >> t;

		string line = "";
		for (int a = 0; a < n; ++a){
			for (int s = 0; s < k; ++s){
				line += t[a];
			}
		}

		for (int s = 0; s < k; ++s){
			fout << line << endl;
		}
	}
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}	