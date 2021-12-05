/** Code by 1egend **/
// Problem: USACO 2017 February Contest, Silver Problem 1. Why Did the Cow Cross the Road
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;

ifstream fin("helpcross.in");
ofstream fout("helpcross.out");

void solve(){
	int c, n;
	fin >> c >> n;
	vector <int> chickens;
	for (int i = 0; i < c; ++i){
		static int a;
		fin >> a;
		chickens.pb(a);
	}
	sort(chickens.begin(), chickens.end());

	vector <pair<int, int>> cows;
	for (int i = 0; i < n; ++i){
		static int a, b;
		fin >> a >> b;
		cows.pb(make_pair(b, a));
	}
	sort(cows.begin(), cows.end());
	
	int ans = 0;
	int b = 0;
	for (int i = 0; i < c; ++i){
		for (int x = b; x < cows.size(); ++x){
			if (cows[x].first < chickens[i]){
				++b;
				continue;
			}

			if (cows[x].second <= chickens[i]){
				cows.erase(cows.begin() + x);
				++ans;
				break;
			}
		}
	}

	fout << ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}	