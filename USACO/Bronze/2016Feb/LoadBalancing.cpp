/** Code by 1egend **/
// Problem: USACO 2016 February Contest, Bronze Problem 3. Load Balancing

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;

ifstream fin("balancing.in");
ofstream fout("balancing.out");

void solve(){
	int n, b;
	fin >> n >> b;

	vector <pair<int, int>> coords;
	vector <int> ys;
	vector <int> xs;

	for (int i = 0; i < n; ++i){
		int x, y;
		fin >> x >> y;
		coords.pb(make_pair(x, y));
		ys.pb(y);
		xs.pb(x);
	}
	sort(ys.begin(), ys.end());
	sort(xs.begin(), xs.end());
	int mxA, mxB, myA, myB;
	int centerX, centerY;

	if (n % 2){
		// odd
		mxA = xs[floor(n/2.0)] - 1;
		mxB = xs[floor(n/2.0)] + 1;
		myA = ys[floor(n/2.0)] - 1;
		myB = ys[floor(n/2.0)] + 1;

		int p1 = 0, p2 = 0;
		for (int i = 0; i < n; ++i){
			if (ys[i] < myA){
				++p1;
			}
			if (ys[i] < myB){
				++p2;
			}
			else{
				break;
			}
		}
		int centerY = (n - p1) > p2 ? myB : myA;

		p1 = 0; p2 = 0;
		for (int i = 0; i < n; ++i){
			if (xs[i] < mxA){
				++p1;
			}
			if (xs[i] < mxB){
				++p2;
			}
			else{
				break;
			}
		}
		int centerX = (n - p1) > p2 ? mxB : mxA;
	}
	else{
		// even 
		int sX = xs[n/2] + xs[n/2 - 1];
		centerX = sX/2;

		int sY = ys[n/2] + ys[n/2 - 1];
		centerY = sY/2;
	}

	int l = 0, m = 0, o = 0, p = 0;
	for (int i = 0; i < n; ++i){
		pair<int, int> coord = coords[i];
		if (coord.first < centerX){
			if (coord.second < centerY){
				++l;
			}
			else{
				++m;
			}
		}
		else{
			if (coord.second < centerY){
				++p;
			}
			else{
				++o;
			}
		}
	}

	fout << max<int>(max<int>(max<int>(l, m), o), p);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}	