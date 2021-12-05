/** Code by 1egend **/
// Problem: USACO 2017 December Contest, Bronze Problem 3. Milk Measurement
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;

ifstream fin("measurement.in");
ofstream fout("measurement.out");

void solve(){
	int n;
	fin >> n;
	vector<tuple<int, string, int>> measurements;
	for (int i = 0; i < n; ++i){
		int a, c; string b;
		fin >> a >> b >> c;
		measurements.pb(make_tuple(a, b, c));
	}
	sort(measurements.begin(), measurements.end());
	measurements.pb(make_tuple(-1, "foo", 0));
	vector<pair<int, string>> cows = {make_pair(7, "Bessie"), make_pair(7, "Elsie"), make_pair(7, "Mildred")};
	vector<string> winners = {"Bessie", "Elsie", "Mildred"};
	int ans = 0;
	for (int i = 0; i < n; ++i){
		if (get<1>(measurements[i]) == "Bessie"){
			cows[0].first += get<2>(measurements[i]);
		}
		else if(get<1>(measurements[i]) == "Elsie"){
			cows[1].first += get<2>(measurements[i]);
		}
		else{
			cows[2].first += get<2>(measurements[i]);
		}

		if (get<0>(measurements[i]) != get<0>(measurements[i + 1])){
			vector<pair<int, string>> sorted = cows;
			sort(sorted.begin(), sorted.end());
			vector<string> top;
			for (int x = 0; x < 3; ++x){
				if (sorted[x].first == sorted[2].first){
					top.pb(sorted[x].second);
				}
			}
			if (top != winners){
				++ans;
			}
			winners = top;
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