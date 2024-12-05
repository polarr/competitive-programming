/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-12-02
 * Contest: Codeforces 2047
 * Problem: C
**/

#include <bits/stdc++.h>
using namespace std;

// Order statistic tree
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T>
using Tree =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    int n; cin >> n;
    Tree<tuple<int, int, int>> citiesx;
    Tree<tuple<int, int, int>> citiesy;

    vector<int> xs;
    vector<int> ys;
    for (int i = 0; i < n; i++){
        int x, y; cin >> x >> y;
        xs.pb(x); ys.pb(y);

        citiesx.insert({x, y, i});
        citiesy.insert({x, y, i});
    }

    pair<int, int> ans;

    auto prune[&](vector<int>& arr){
        vector<int> a;
        for (int i = 1; i < arr.size(); i++){
            if (arr[i] != arr[i - 1]){
                a.pb(arr[i]);
            }
        }

        arr = a;
    }

    sort(xs.begin(), xs.end());
    sort(ys.begin(), ys.end());
    prune(xs);
    prune(ys);

    auto query = [&](int){

    }

    auto check = [&](int a){
        for (int yi = 0; yi < ys.size(); yi++){
            int y = ys[yi];

            int minX = -1e9;
            int maxX = 1e9;

            // UL
            int l = 0, r = 2 * xs.size() - 1;
            while (l < r){
                int mid = (l + r + 1)/2;

                if (){

                }
            }

            // UR
            l = 0, r = xs.size() - 1;
            while (l < r){
                int mid = (l + r + 1)/2;

                if (){

                }
            }

            // DL
            l = 0, r = xs.size() - 1;
            while (l < r){
                int mid = (l + r + 1)/2;

                if (){

                }
            }

            // DL
            l = 0, r = xs.size() - 1;
            while (l < r){
                int mid = (l + r + 1)/2;

                if (){

                }
            }

            if (minX <= maxX){
                ans = {y, minX};
                return true;
            }
        }
    }

    int l = 0;
    int r = floor(n * 1.0/4.0);

    while (l < r){
        int mid = (l + r + 1)/2;

        if (check(mid)){
            l = mid;
        } else {
            r = mid;
        }
    }

    cout << ans << endl;
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