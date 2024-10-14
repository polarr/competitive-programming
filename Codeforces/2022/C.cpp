/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-10-13
 * Contest: Codeforces 2022
 * Problem: C
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    int n; cin >> n;

    vector<vector<int>> grid(2, vector<int>(n, 0));
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < n; j++){
            char s; cin >> s;
            if (s == 'A'){
                grid[i][j] = 1;
            }
        }
    }

    auto gotVote = [](int a, int b, int c){
        return (int)((a && b) || (b && c) || (c && a));
    };

    auto horVote = [&](int i, int j){
        return gotVote(grid[i][j - 1], grid[i][j], grid[i][j + 1]);
    };

    auto jagVote = [&](int i, int j){
        if (i == 0){
            if (j % 3 == 2){
                return gotVote(grid[i][j], grid[i][j - 1], grid[i + 1][j]);
            }

            return gotVote(grid[i][j], grid[i][j + 1], grid[i + 1][j]);
        }
        
        if (j % 3 == 2){
            return gotVote(grid[i][j], grid[i][j - 1], grid[i - 1][j]);
        }

        return gotVote(grid[i][j], grid[i][j + 1], grid[i - 1][j]);
    };

    vector<int> A(n/3, 0), B(n/3, 0), C(n/3, 0);

    B[0] = jagVote(0, 0);
    C[0] = jagVote(1, 0);
    A[0] = max(horVote(0, 1) + horVote(1, 1), max(jagVote(1, 2) + B[0], jagVote(0, 2) + C[0]));

    for (int i = 1; i < n/3; i++){
        int real = 3 * i;
        B[i] = max(jagVote(0, real) + A[i - 1], horVote(0, real) + horVote(1, real - 1) + B[i - 1]);
        C[i] = max(jagVote(1, real) + A[i - 1], horVote(1, real) + horVote(0, real - 1) + C[i - 1]);
        A[i] = max(horVote(0, real + 1) + horVote(1, real + 1) + A[i - 1], max(jagVote(1, real + 2) + B[i], jagVote(0, real + 2) + C[i]));
    }

    cout << A[n/3 - 1] << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; ++t){
        // cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}