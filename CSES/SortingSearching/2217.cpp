/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-04-13
 * Contest: CSES Problemset
 * Problem: 2217. Sorting and Searching - Collecting Numbers II
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

vector<int> idx;
vector<int> arr;

int changeup(int i, int nidx){
    if (i == idx.size() - 1){
        return 0;
    }

    if (idx[i + 1] < idx[i] && idx[i + 1] > nidx){
        return -1;
    }

    if (idx[i + 1] > idx[i] && idx[i + 1] < nidx){
        return 1;
    }

    return 0;
}

int changedown(int i, int nidx){
    if (i == 1){
        return 0;
    }

    if (idx[i - 1] < idx[i] && idx[i - 1] > nidx){
        return 1;
    }

    if (idx[i - 1] > idx[i] && idx[i - 1] < nidx){
        return -1;
    }

    return 0;
}

int change(int i, int nidx){
    return changeup(i, nidx) + changedown(i, nidx);
}

void solve(){
    int n, m; cin >> n >> m;

    idx = vector<int>(n + 1);
    arr = vector<int>(n + 1);

    for (int i = 0; i < n; i++){
        int x; cin >> x;
        idx[x] = i + 1;
        arr[i + 1] = x;
    }
    
    int ans = 1;
    for (int i = 1; i < n; i++){
        if (idx[i + 1] < idx[i]){
            ans++;
        }
    }

    for (int i = 0; i < m; i++){
        int a, b; cin >> a >> b;

        if (arr[a] < arr[b]){
            swap(a, b);
        }

        int numa = arr[a];
        int numb = arr[b];

        if (numa - numb == 1){
            if (idx[numa] < idx[numb]){
                ans--;
            } else {
                ans++;
            }

            ans += changeup(numa, idx[numb]);
            ans += changedown(numb, idx[numa]);
        }
        else {
            ans += change(numa, idx[numb]);
            ans += change(numb, idx[numa]);
        }

        swap(idx[numa], idx[numb]);
        swap(arr[a], arr[b]);

        cout << ans << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}