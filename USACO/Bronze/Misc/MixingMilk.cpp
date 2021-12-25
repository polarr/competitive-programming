/** Code by 1egend **/
#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define pb push_back
const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;

ifstream fin("mixmilk.in");
ofstream fout("mixmilk.out");

void solve(){
	vector<pair<int, int>> buckets;
	for (int i = 0; i < 3; ++i){
		int a, b;
		fin >> a >> b;
		buckets.pb(make_pair(a, b));
	}
	for (int i = 0; i < 100; ++i){
		int pour = min <int> (buckets[i % 3].second, buckets[(i + 1) % 3].first - buckets[(i + 1) % 3].second);
		buckets[i % 3].second -= pour;
		buckets[(i + 1) % 3].second += pour;
	}
	for (int i = 0; i < 3; ++i){
		fout << buckets[i].second << endl;
	}
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}	