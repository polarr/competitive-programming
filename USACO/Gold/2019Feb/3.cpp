/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-01-23
 * Contest: USACO 2019 February Contest
 * Problem: Gold P3. Painting the Barn
**/

#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;

const string iofilename = "paintbarn";
ifstream fin(iofilename + ".in");
ofstream fout(iofilename + ".out");

vector<vector<int>> prefix(201, vector<int>(201, 0));

int rectsum(int x1, int y1, int x2, int y2){
    return (
        prefix[y2 + 1][x2 + 1] - prefix[y1][x2 + 1] - prefix[y2 + 1][x1] + prefix[y1][x1]
    );
}

// Use fstream (fin, fout) instead of iostream!
void solve(){
    vector<vector<int>> barn(201, vector<int>(201, 0));
    vector<vector<int>> area(201, vector<int>(201, 0));

    int n, k;
    fin >> n >> k;

    for (int i = 0; i < n; i++){
        int x1, y1, x2, y2;
        fin >> x1 >> y1 >> x2 >> y2;

        barn[x1][y1]++;
        barn[x2][y2]++;
        barn[x1][y2]--;
        barn[x2][y1]--;
    }

    int current = 0;

    for (int i = 0; i < 200; i++){
        for (int j = 0; j < 200; j++){
            if (j > 0){
                barn[i][j] += barn[i][j - 1];
            }
            if (i > 0){
                barn[i][j] += barn[i - 1][j];
            }
            if (i > 0 && j > 0){
                barn[i][j] -= barn[i - 1][j - 1];
            }
            if (barn[i][j] == k){
                area[i][j] = -1;
                current++;
            } else if (barn[i][j] == (k - 1)){
                area[i][j] = 1;
            }
        }
    }

	for (int r = 1; r < 201; r++) {
		for (int c = 1; c < 201; c++) {
			prefix[r][c] =
			    (prefix[r - 1][c] + prefix[r][c - 1] -
			     prefix[r - 1][c - 1] + area[r - 1][c - 1]);
		}
	}
    
    int paint = 0;

    vector<int> top(201, 0);
    vector<int> bottom(201, 0);
    vector<int> left(201, 0);
    vector<int> right(201, 0);

    for (int start = 0; start < 200; start++){
        for (int end = start; end < 200; end++){
            int bottoms = 0;
            int bottomm = 0;
            int lefts = 0;
            int leftm = 0;
            int tops = 0;
            int topm = 0;
            int rights = 0;
            int rightm = 0;
            
            for (int i = 0; i < 200; i++){
                bottoms = max(0, bottoms + rectsum(start, i, end, i));
                bottomm = max(bottomm, bottoms);
                bottom[i + 1] = max(bottom[i + 1], bottomm);

                lefts = max(0, lefts + rectsum(i, start, i, end));
                leftm = max(leftm, lefts);
                left[i + 1] = max(left[i + 1], leftm);
            }
            
            for (int i = 199; i >= 0; i--){
                tops = max(0, tops + rectsum(start, i, end, i));
                topm = max(topm, tops);
                top[i] = max(top[i], topm);

                rights = max(0, rights + rectsum(i, start, i, end));
                rightm = max(rightm, rights);
                right[i] = max(right[i], rightm);
            }
        }
    }

    for (int i = 0; i < 201; i++){
        paint = max(paint, left[i] + right[i]);
        paint = max(paint, top[i] + bottom[i]);
    }

    fout << current + paint;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    solve();
    return 0;
}