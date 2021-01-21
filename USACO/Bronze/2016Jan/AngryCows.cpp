/** Code by 1egend **/
// Problem: Angry Cows - USACO 2016 January Bronze Q2
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;

ifstream fin("angry.in");
ofstream fout("angry.out");

int simulateExploding(int chosen, vector <int> pos){
	int ans = 1;
	int left = pos[chosen];
	int orgL = left;
	int right = pos[chosen];
	int orgR = right;

	int z = 1;
	bool done = false;
	for (int i = chosen - 1; i >= 0; --i){
		if (orgL - pos[i] <= z){
			left = pos[i];
			done = false;
			++ans;
			// cout << left << " ";
		}
		else{
			if (!done && left != orgL){
				orgL = left;
				++z;
				++i;
				done = true;
			}
			else{
				break;
			}
		}
	}

	z = 1;
	done = false;
	for (int i = chosen + 1; i < pos.size(); ++i){
		if (pos[i] - orgR <= z){
			right = pos[i];
			done = false;
			++ans;
			// cout << right << " ";
		}
		else{
			if (!done && right != orgR){
				orgR = right;
				++z;
				--i;
				done = true;
			}
			else{
				break;
			}
		}
	}

	return ans;
}

void solve(){
	int x;
	fin >> x;

	vector <int> pos;
	for (int i = 0; i < x; ++i){
		int k;
		fin >> k;
		pos.pb(k);
	}
	sort(pos.begin(), pos.end());

	int ans = 1;
	for (int i = 0; i < x; ++i){
		ans = max <int> (ans, simulateExploding(i, pos));
	}
	fout << ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}	