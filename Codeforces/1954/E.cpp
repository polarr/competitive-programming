/**
 * Solution by 1egend (polarity.sh)
 * Date: 
 * Contest: 
 * Problem: 
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

int fast_ceil(int x, int k){
    int r = x/k;
    return (x % k == 0 ? r:r + 1);
}

void solve(){
    int n;
    cin >> n;

    vector<int> arr;
    int mx = 0;
    for (int i = 0; i < n; i++){
        int a; cin >> a;
        if (arr.size() > 0 && a == arr[arr.size() - 1]){
            continue;
        }
        arr.pb(a);
        mx = max(mx, a);
    }

    vector<int> extreme;

    for (int i = 0; i < arr.size(); i++){
        if ((i == 0 || arr[i] > arr[i - 1]) && (i == arr.size() - 1 || arr[i] > arr[i + 1])){
            extreme.pb(arr[i]);
            continue;
        }

        if(i > 0 && i < arr.size() - 1 && arr[i] < arr[i - 1] && arr[i] < arr[i + 1]){
            extreme.pb(-arr[i]);
        }
    }

    vector<int> store(extreme.size(), 0);

    ll pos_sum = 0;
    ll neg_sum = 0;
    for (int i = 0; i < extreme.size(); i++){
        ll t = (ll)abs(extreme[i]);

        if (extreme[i] < 0){
            neg_sum += t;
        } else {
            pos_sum += t;
        }
    }

    for (int k = 1; k <= mx; k++){
        int ans = 0;
        ll pos_ans = pos_sum;
        ll neg_ans = neg_sum;
        for (int i = 0; i < extreme.size(); i++){
            int x = extreme[i];

            int t = abs(x);

            int add = 0;
            if (t % k != 0){
                add = k - (t % k);
            }

            if (x < 0){
                neg_ans += add;
            } else {
                pos_ans += add;
            }
        }

        cout << (pos_ans - neg_ans)/k << " ";
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}