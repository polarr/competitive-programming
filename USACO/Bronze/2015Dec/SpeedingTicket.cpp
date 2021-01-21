/** Code by 1egend **/
// Problem: Speeding Ticket - USACO 2015 DEC BRONZE Q2
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;

ifstream fin("speeding.in");
ofstream fout("speeding.out");

void solve(){
	int n, m;
	fin >> n >> m;
	vector<pair<int, int>> roads;
	vector<pair<int, int>> speeds;
	for (int i = 0; i < n; ++i){
		int a, b;
		fin >> a >> b;
		roads.pb(make_pair(a, b));
	}
	for (int i = 0; i < m; ++i){
		int a, b;
		fin >> a >> b;
		speeds.pb(make_pair(a, b));
	}

	int ans = 0;
	int segStart = 0;
	int x = 0;
	for (int i = 0; i < m; ++i){
		pair <int, int> speed = speeds[i];
		int segEnd = segStart + speed.first;
		int roadStart = 0;
		for (int k = 0; k < n; ++k){
			pair <int, int> road = roads[k];
			int roadEnd = roadStart + road.first;
			if (roadEnd <= segStart){
				roadStart += road.first;
				// cout << ans << endl;
				// cout << roadStart << " " << road.first << " " << roadEnd << endl;
				continue;
			}
			// cout << ans << endl;
			// cout << roadStart << " " << road.first << " " << roadEnd << endl;
			if (roadStart >= segEnd){
				break;
			}
			ans = max<int> (ans, speed.second - road.second);
			roadStart += road.first;
		}
		segStart += speed.first;
	}
	fout << ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}	