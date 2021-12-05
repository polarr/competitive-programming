/** Code by 1egend **/
// Problem: USACO 2017 December Contest, Bronze Problem 2. The Bovine Shuffle
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;

ifstream fin("shuffle.in");
ofstream fout("shuffle.out");

void solve(){
	int n;
	fin >> n;
	vector <int> order(n, 0);
	vector <int> shuffle;
	vector <int> cows;
	for (int i = 0; i < n; ++i){
		order[i] = i;
		int pos;
		fin >> pos;
		shuffle.pb(pos);
	}
	for (int i = 0; i < n; ++i){
		int cow;
		fin >> cow;
		cows.pb(cow);
	}

	for (int i = 0; i < 3; ++i){
		vector <int> newOrder(n, 0);
		for (int a = 0; a < n; ++a){
			newOrder[shuffle[a] - 1] = order[a];
		}
		order = newOrder;
	}

	vector <int> realOrder(n, 0);
	for (int i = 0; i < n; ++i){
		realOrder[order[i]] = cows[i];
	}

	for (int i = 0; i < n; ++i){
		fout << realOrder[i] << endl;
	}
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}	