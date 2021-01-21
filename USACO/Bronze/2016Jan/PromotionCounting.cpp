/** Code by 1egend **/
// Problem: Promotion Counting - USACO 2016 January Bronze Q1
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;

ifstream fin("promote.in");
ofstream fout("promote.out");

void solve(){
	vector <pair<int, int>> divisions;
	for (int i = 0; i < 4; ++i){
		int a, b;
		fin >> a >> b;
		divisions.pb(make_pair(a, b));
	}
	vector <int> ans (3, 0);
	for (int i = 3; i > 0; --i){
		pair <int, int> division = divisions[i];
		int promoted = division.second - division.first;
		for (int x = 0; x < i; ++x){
			ans[x] += promoted;
		} 
	}
	for (auto i: ans){
		fout << i << endl;
	}
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}	