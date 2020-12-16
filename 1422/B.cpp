/** Code by 1egend **/
#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;

int checkNums(vector <int> x){
    int sum = 0;
    for (int i = 0; i < x.size(); ++i){
        sum += x[i];
    }
    int sum1 = floor(sum/x.size());
    int sum2 = ceil(sum/x.size());
    int ans1 = 0;
    int ans2 = 0;
    for (int i = 0; i < x.size(); ++i){
        ans1 += abs(x[i] - sum1);
        ans2 += abs(x[i] - sum2);
    }
    return min<int>(ans1, ans2);
}
void solve(){
    int n, m;
    cin >> n >> m;
    vector <vector <int>> x(n);
    for (int i = 0; i < n; i++){
        for (int z = 0; z < m; z++){
            int a;
            cin >> a;
            x[i].push_back(a);
        }
    }
    int ans = 0;
    for (int i = 0; i < ceil(n/2.0); i++){
        for (int z = 0; z < ceil(m/2.0); z++){
            vector <int> s;
            s.push_back(x[i][z]);
            if (i != floor(n/2.0)){
                s.push_back(x[n - i - 1][z]);
            }
            if (z != floor(m/2.0)){
                s.push_back(x[i][m - z - 1]);
            }
            if (i != floor(n/2.0) && z != floor(m/2.0)){
                s.push_back(x[n - i - 1][m - z - 1]);
            }
            ans += checkNums(s);
        }
    }
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        // cout << "Case #" << t  << ": " << endl;
        solve();
    }
    return 0;
}