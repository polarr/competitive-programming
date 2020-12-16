/** Code by 1egend **/
#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;

bool checkA(vector <int> arr, int a, int k){
    int prev = -1;
    for (int i = 0; i < arr.size(); ++i){
        if (i - prev > k){
            return false;
        }
        if (arr[i] == a){
            if (i >= arr.size() - k){
                return true;
            }
            prev = i;
        }
    }
    if (arr.size() - prev > k){
        return false;
    }
    return true;
}
void solve(){
    int n;
    cin >> n;
    vector <int> arr;
    for (int i = 0; i < n; ++i){
        int k;
        cin >> k;
        arr.push_back(k);
    }
    vector <int> ans;
    int lowest = 1;
    for (int k = n; k >= 1; k--){
        vector <int> clone(k);
        copy(arr.begin(), arr.begin() + k, clone.begin());
        sort(clone.begin(), clone.end());
        int found = false;
        for (int i = 0; i < k; i++){
            if (clone[i] < lowest || (i > 0 && clone[i] == clone[i - 1])){
                continue;
            }
            if (checkA(arr, clone[i], k)){
                ans.push_back(clone[i]);
                found = true;
                lowest = clone[i];
                break;
            }
        }
        if (!found){
            ans.push_back(-1);
            break;
        }
    }
    for (int i = 0; i < n - ans.size(); i ++){
        cout << "-1 ";
    }
    for (int i = ans.size() - 1; i >= 0; i--){
        cout << ans[i] << " ";
    }
    cout << endl;
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