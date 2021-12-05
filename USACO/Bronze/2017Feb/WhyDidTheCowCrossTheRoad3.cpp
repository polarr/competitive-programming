/** Code by 1egend **/
// Problem: USACO 2017 February Contest, Bronze Problem 3. Why Did the Cow Cross the Road III
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;

ifstream fin("cowqueue.in");
ofstream fout("cowqueue.out");

void solve(){
	int n;
	fin >> n;
	vector <pair<int, int>> cows;
	for (int i = 0; i < n; ++i){
		int a, b;
		fin >> a >> b;
		cows.pb(make_pair(a, b));
	}
	sort(cows.begin(), cows.end());
	int time = 0;
	for (int i = 0; i < n; ++i){
		pair<int, int> cow = cows[i];
		time = max<int>(time, cow.first);
		time += cow.second;
	}

	fout << time;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}	