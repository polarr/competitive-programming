/** Code by 1egend **/
// Problem: 
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;

ifstream fin("lemonade.in");
ofstream fout("lemonade.out");

void solve(){
	int x;
	fin >> x;
	vector <int> line;
	for (int i = 0; i < x; ++i){
		int t;
		fin >> t;
		line.push_back(t);
	}
	sort(line.begin(), line.end());
	for (int i = 0; i < x; ++i){
		if (line[i] >= x - i - 1){
			fout << x - i;
			break;
		}
	}
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}	