/** Code by 1egend **/
// Problem: 
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
	vector <string, string> citystates;
	for (int i = 0; i < n; ++i){
		string a, b;
		cin >> a >> b;
		citystates.pb(make_pair(a.substr(0, 2), b));
	}

	vector <string, string> sorted = citystates;
	sort(citystates.begin(), citystates.end());
	for (int a = 0; a < n - 1; ++a){
		int c1 = citystates[a].first;
		int s1 = citystates[a].second;

		
	}
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}	