/** Code by 1egend **/
#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;

void solve(){
	int n;
	cin >> n;
	vector <int> numbers;
	for (int i = 0; i < n; ++i){
		int t;
		cin >> t;
		numbers.push_back(t);
	}
	sort(numbers.begin(), numbers.end());
	int ans = 1;
	for (int i = 1; i < n; ++i){
		if (numbers[i] != numbers [i - 1]){
			++ans;
		}
	}
	cout << ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}	