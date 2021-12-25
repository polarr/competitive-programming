/** Code by 1egend **/
// Problem: CCC Problem S3 2020 Searching for Strings
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;

// ifstream fin(".in");
// ofstream fout(".out");

void solve(){
	string needle;
	string haystack;
	cin >> needle >> haystack;
	sort(needle.begin(), needle.end());
	int ans = 0;
	do {
		if (haystack.find(needle) != string::npos){
			++ans;
		}
	}while(next_permutation(needle.begin(), needle.end()));
	cout << ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}	