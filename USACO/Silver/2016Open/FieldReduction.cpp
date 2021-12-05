/**
 * Solution by 1egend
 * Date: 7/12/2021
 * Contest: USACO 2016 Open Contest
 * Problem: Silver - P1. Field Reduction
**/

#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;

const string iofilename = "reduce";
ifstream fin(iofilename + ".in");
ofstream fout(iofilename + ".out");

int area(vector<pair<int, int>> c){
	int maxX = 0, minX = INT_MAX, maxY = 0, minY = INT_MAX;
	for (int i = 0; i < c.size(); ++i){
		maxX = max<int>(c[i].first, maxX);
		maxY = max<int>(c[i].second, maxY);

		minX = min<int>(c[i].first, minX);
		minY = min<int>(c[i].second, minY);
	}

	return (maxX - minX) * (maxY - minY);
}

// Use fstream (fin, fout) instead of iostream!
void solve(){
	int n;
	fin >> n;

	vector <pair<int, int>> coords;
	vector <pair<int, int>> x;
	vector <pair<int, int>> y;

	for (int i = 0; i < n; ++i){
		static int a, b;
		fin >> a >> b;
		
		coords.pb(make_pair(a, b));
		x.pb(make_pair(a, i)); y.pb(make_pair(b, i));
	}

	sort(x.begin(), x.end()); sort(y.begin(), y.end());
	set <int> pool;
	for (int i = 0; i < 3; ++i){
		pool.insert(x[i].second); pool.insert(y[i].second);
	}
	for (int i = n - 3; i < n; ++i){
		pool.insert(x[i].second); pool.insert(y[i].second);
	}

	vector <int> p;
	for (auto i: pool){
		p.pb(i);
	}

	int ans = INT_MAX;
	for (int a = 0; a < p.size() - 2; ++a){
		for (int b = a + 1; b < p.size() - 1; ++b){
			for (int c = b + 1; c < p.size(); ++c){
				vector <pair<int, int>> d = coords;
				d[p[c]] = d.back();
				d.pop_back();
				d[p[b]] = d.back();
				d.pop_back();
				d[p[a]] = d.back();
				d.pop_back();

				ans = min<int>(ans, area(d));
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