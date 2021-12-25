/** Code by 1egend **/
#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;

void solve(){
	int n;
	cin >> n;
	vector <vector <int>> rectangles(n);
	for (int i = 0; i < n; ++i){
		for (int x = 0; x < 4; ++x){
			int t;
			cin >> t;
			rectangles[i].push_back(t);
		}
	}
	int ans = n;
	for (int a = 0; a < n; ++a){
		for (int b = 0; b < n; ++b){
			if (a == b){
				continue;
			}
			vector <int> rect1 = rectangles[a];
			vector <int> rect2 = rectangles[b];
			if (rect1[0] >= rect2[0] && rect1[1] >= rect2[1] && rect1[2] <= rect2[2] && rect1[3] <= rect2[3]){
				//engulfed
				ans --;
				break;
			}
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