/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-12-22
 * Contest: Google Kickstart 2921 A
 * Problem: D
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

// Half correct idea, too lazy to implement editorial
/**
void solve(int tc){
    int n; cin >> n;

    vector<vector<int>> a(n, vector<int>(n));
    vector<vector<int>> b = a;

    using T = pair<ll, pair<int, int>>;
    priority_queue<T, vector<T>, greater<T>> pq;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> b[i][j];
        }
    }

    vector<int> r(n);
    vector<int> c(n);

    for (int i = 0; i < n; i++){
        cin >> r[i];
    }

    for (int i = 0; i < n; i++){
        cin >> c[i];
    }

    if (n == 1){
        cout << "Case #" << tc << ": 0" << endl;
        return;
    }

    vector<int> rowsRemain(n, n);
    vector<int> colsRemain(n, n);

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            pq.push({b[i][j], {i, j}});
        }
    }

    vector<vector<bool>> checked(n, vector<bool>(n, false));

    int ans = 0;

    while (!pq.empty()){
        auto [cost, node] = pq.top();
        pq.pop();
        
        int i = node.first, j = node.second;

        if (checked[i][j]){
            continue;
        }

        checked[i][j] = true;
        ans += cost;

        rowsRemain[i]--;
        colsRemain[j]--;

        // cout << i << " " << j << " " << rowsRemain[i] << " " << colsRemain[j] << endl;

        if (rowsRemain[i] == 1){
            for (int jj = 0; jj < n; jj++){
                if (!checked[i][jj]){
                    pq.push({0, {i, jj}});
                    break;
                }
            }
            // cout << "R" << i << endl;
        }

        if (colsRemain[j] == 1){
            for (int ii = 0; ii < n; ii++){
                if (!checked[ii][j]){
                    pq.push({0, {ii, j}});
                    break;
                }
            }

            // cout << "C" << j << endl;
        }
    }

    cout << "Case #" + to_string(tc) + ": " + to_string(ans) << endl;
}
*/

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; ++t){
        // cout << "Case #" << t << ": ";
        solve(t);
    }
    return 0;
}