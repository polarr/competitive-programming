/** Code by 1egend **/
// Problem: 
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;

ifstream fin("div7.in");
ofstream fout("div7.out");

void solve(){
	int n;
	fin >> n;
	
	vector<int> residue(n, -1);
	int ans = 0;
	int sum = 0;
	for (int i = 0; i < n; ++i){
		int z;
		fin >> z;
		sum = (sum + z) % 7;
		if (residue[sum] < 0 && sum > 0){
			residue[sum] = i;
			continue;
		}
		ans = max(ans, i - residue[sum]);
	}

	fout << ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}	