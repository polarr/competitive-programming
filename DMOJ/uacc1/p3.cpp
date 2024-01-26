/**
 * Solution by 1egend (polarity.sh)
 * Date: 2023-01-08
 * Contest: DMOJ UACC 1
 * Problem: P3 - Cheeky Checkers
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

int maxCapture(vector <string> board, int i, int j, int captures){
    int ans = captures;
    vector <string> tempBoard;
    if (i - 2 >= 0 && j - 2 >= 0 && board[i - 2][j - 2] == '.' && board[i - 1][j - 1] == 'B'){
        tempBoard = board;
        tempBoard[i][j] = '.';
        tempBoard[i - 1][j - 1] = '.';
        tempBoard[i - 2][j - 2] = 'A';
        ans = max(ans, maxCapture(tempBoard, i - 2, j - 2, captures + 1));
    }
    if (i - 2 >= 0 && j + 2 < 8 && board[i - 2][j + 2] == '.' && board[i - 1][j + 1] == 'B'){
        tempBoard = board;
        tempBoard[i][j] = '.';
        tempBoard[i - 1][j + 1] = '.';
        tempBoard[i - 2][j + 2] = 'A';
        ans = max(ans, maxCapture(tempBoard, i - 2, j + 2, captures + 1));
    }
    if (i + 2 < 8 && j - 2 >= 0 && board[i + 2][j - 2] == '.' && board[i + 1][j - 1] == 'B'){
        tempBoard = board;
        tempBoard[i][j] = '.';
        tempBoard[i + 1][j - 1] = '.';
        tempBoard[i + 2][j - 2] = 'A';
        ans = max(ans, maxCapture(tempBoard, i + 2, j - 2, captures + 1));
    }
    if (i + 2 < 8 && j + 2 < 8 && board[i + 2][j + 2] == '.' && board[i + 1][j + 1] == 'B'){
        tempBoard = board;
        tempBoard[i][j] = '.';
        tempBoard[i + 1][j + 1] = '.';
        tempBoard[i + 2][j + 2] = 'A';
        ans = max(ans, maxCapture(tempBoard, i + 2, j + 2, captures + 1));
    }
    return ans;
}

void solve(){
    vector<string> board;
    for (int i = 0; i < 8; i++){
        string row;
        cin >> row;
        board.pb(row);
    }

    int ans = 0;
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            if (board[i][j] == 'A'){
                ans = max(ans, maxCapture(board, i, j, 0));
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