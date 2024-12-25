/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-12-24
 * Contest: Codeforces 2043
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

    int c = -10;

    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        if (arr[i] != 1 && arr[i] != -1){
            c = i;
        }
    }

    auto maxSum = [&](int i, int j, int m){
        int sum = 0;
        int curr = 0;
        for (int k = i; k < j; k++){
            curr += arr[k] * m;
            if (curr < 0){
                curr = 0;
            }

            sum = max(sum, curr);
        }

        return sum;
    };

    if (c == -10){
        int minAns = 0;
        int maxAns = 0;

        minAns = min(minAns, -maxSum(0, n, -1));
        maxAns = max(maxAns, maxSum(0, n, 1));

        cout << maxAns - minAns + 1 << endl;

        for (int i = minAns; i <= maxAns; i++){
            cout << i << " ";
        }

        cout << endl;

        return;
    }

    int sL = 0, mL = 0, sR = 0, mR = 0;

    int s = 0;

    for (int i = c - 1; i >= 0; i--){
        s += arr[i];
        sL = min(s, sL);
        mL = max(s, mL);
    }

    s = 0;

    for (int i = c + 1; i < n; i++){
        s += arr[i];
        sR = min(s, sR);
        mR = max(s, mR);
    }

    int minAns = 0;
    int maxAns = 0;

    vector<int> ans;

    for (int i = arr[c] + sL + sR; i <= arr[c] + mL + mR; i++){
        ans.pb(i);
    }

    minAns = min(minAns, -maxSum(0, c, -1));
    minAns = min(minAns, -maxSum(c + 1, n, -1));
    maxAns = max(maxAns, maxSum(0, c, 1));
    maxAns = max(maxAns, maxSum(c + 1, n, 1));

    for (int i = minAns; i <= maxAns; i++){
        ans.pb(i);
    }
    
    sort(ans.begin(), ans.end());

    vector<int> a = {ans[0]};

    for (int i = 1; i < ans.size(); i++){
        if (ans[i] != ans[i - 1]){
            a.pb(ans[i]);
        }
    }

    cout << a.size() << endl;

    for (int i = 0; i < a.size(); i++){
        cout << a[i] << " ";
    }

    cout << endl;
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