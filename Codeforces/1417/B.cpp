/** Code by 1egend **/
#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;

vector<pair<int, int>> sortArr(vector <int> arr, int n) 
{ 
    vector<pair<int, int>> vp; 
    for (int i = 0; i < n; ++i) { 
        vp.push_back(make_pair(arr[i], i)); 
    } 
    sort(vp.begin(), vp.end()); 
  
    return vp;
} 

void solve(){
    int n;
    int k;
    cin >> n >> k;
    vector <int> arr;
    for (int i = 0; i < n; ++i){
        int a;
        cin >> a;
        arr.push_back(a);
    }
    vector <int> ans(n);
    fill(ans.begin(), ans.end(), 0);
    vector <pair <int, int>> sorted = sortArr(arr, n);
    int last = n-1;
    for (int i = 0; i < last; ++i){
        int num1 = sorted[i].first;
        if (num1 > ceil(k/2.0)){
            break;
        }
        bool alert = false;
        for (int j = i + 1; j < n; ++j){
            int num2 = sorted[j].first;
            if (num1 == num2){
                break;
            }
            if (num1 + num2 == k){
                last = j;
                ans[sorted[j].second] = 1;
                alert = true;
            }
            else if (alert){
                break;
            }
        }
    }
    int current = 0;
    for (int i = 0; i < n; ++i){
        if (k % 2 == 0 && sorted[i].first == k/2){
            ans[sorted[i].second] = current;
            current = (current == 0 ? 1:0);
        }
    }

    for (int i = 0; i < n; ++i){
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