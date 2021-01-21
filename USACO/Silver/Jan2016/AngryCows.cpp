/** Code by 1egend **/
// Problem: Angry Cows - USACO 2016 January Silver Q1

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;

ifstream fin("angry.in");
ofstream fout("angry.out");

void solve(){
	int n, k;
	fin >> n >> k;

	vector <pair<int, int>> pos;
	for (int i = 0; i < n; ++i){
		int z;
		fin >> z;
		pos.pb(make_pair(z, z));
	}

	sort(pos.begin(), pos.end());

	int low = 1;
	int merge = n - k;
	for (int i = 0; i < merge; ++i){
		int merging = 0;
		int minLen = INT_MAX;
		for (int x = 0; x < n - 1; ++x){
			int len = pos[x + 1].second - pos[x].first;
			if (len <= minLen){
				minLen = len;
				merging = x;
			}

			if (minLen == low){
				break;
			}
		}

		low = minLen;
		pos[merging].second = pos[merging + 1].second;
		pos.erase(pos.begin() + merging + 1);
		--n;
	}

	int ans = 0;
	// cout << pos.size() << " " << k << endl;
	for (int i = 0; i < pos.size(); ++i){
		ans = max<int> (ans, pos[i].second - pos[i].first);
		// cout << pos[i].first << " " << pos[i].second;
	}
	fout << ceil(ans/2.0);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}	