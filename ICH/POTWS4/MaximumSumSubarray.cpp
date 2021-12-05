/** Code by 1egend **/
#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;

void solve(){
	int n, k;
	cin >> n >> k;
	vector <int> arr;
	for (int i = 0; i < n; ++i){
		int x;
		cin >> x;
		arr.push_back(x);
	}
	int best = INT_MIN;
	for (int i = 0; i <= n - k; ++ i){
		int sum = 0;
		for (int a = i; a < i + k; ++a){
			sum += arr[a];
		}
		best = max<int>(sum, best);
	}
	cout << best;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}	