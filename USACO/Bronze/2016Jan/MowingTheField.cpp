/** Code by 1egend **/
// Problem: Mowing the Field - USACO 2016 January Bronze Q3. 

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;

ifstream fin("mowing.in");
ofstream fout("mowing.out");

void solve(){
	map <pair<int, int>, int> mowed;
	int x = 0; 
	int y = 0;
	int t = 0;
	int n;
	fin >> n;
	int ans = INT_MAX;
	mowed[make_pair(x, y)] = t;

	for (int i = 0; i < n; ++i){
		char d;
		int m;
		fin >> d >> m;
		if (d == 'N'){
			for (int z = 1; z <= m; ++z){
				++t;
				++y;
				if (mowed.count(make_pair(x, y))){
					ans = min <int> (ans, t - mowed[make_pair(x, y)]);
				}
				mowed[make_pair(x, y)] = t;
			}
		}
		else if (d == 'S'){
			for (int z = 1; z <= m; ++z){
				++t;
				--y;
				if (mowed.count(make_pair(x, y))){
					ans = min <int> (ans, t - mowed[make_pair(x, y)]);
				}
				mowed[make_pair(x, y)] = t;
			}
		}
		else if (d == 'E'){
			for (int z = 1; z <= m; ++z){
				++t;
				++x;
				if (mowed.count(make_pair(x, y))){
					ans = min <int> (ans, t - mowed[make_pair(x, y)]);
				}
				mowed[make_pair(x, y)] = t;
			}
		}
		else if (d == 'W'){
			for (int z = 1; z <= m; ++z){
				++t;
				--x;
				if (mowed.count(make_pair(x, y))){
					ans = min <int> (ans, t - mowed[make_pair(x, y)]);
				}
				mowed[make_pair(x, y)] = t;
			}
		}
	}
	fout << (ans == INT_MAX ? -1: ans);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}	