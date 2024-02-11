/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-02-01
 * Contest: Happy Hackers Programming Challenge 1
 * Problem: P3 - Yonder Ridge
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve(){
    int n, m, q, k;
    cin >> n >> m >> q >> k;
    vector<pair<pair<int, int>, int>> ridges;
    vector<set<pair<double, int>>> left(n);
    vector<set<pair<double, int>>> right(n);
    vector<set<pair<double, ull>>> leftSum(n);
    vector<set<pair<double, ull>>> rightSum(n);

    for (int i = 0; i < n; i++){
        int a, b, v;
        cin >> a >> b >> v;
        ridges.pb(make_pair(make_pair(a, b), v));
    }

    for (int i = 0; i < n - 1; i++){
        for (int j = i + 1; j < n; j++){
            pair<pair<int, int>, int> ridge1 = ridges[i];
            pair<pair<int, int>, int> ridge2 = ridges[j];
            pair<int, int> coord1 = ridge1.first;
            pair<int, int> coord2 = ridge2.first;

            if (coord1.first == coord2.first && coord1.second == coord2.second){
                continue;
            }

            if (coord1.first > coord2.first && coord1.second > coord2.second){
                // 1 always above 2
                right[j].insert(make_pair(-1, i));
                continue;
            }

            if (coord2.first > coord1.first && coord2.second > coord1.second){
                // 2 always above 1
                right[i].insert(make_pair(-1, j));
                continue;
            }

            double intersect = (coord2.first - coord1.first) * 1.0 * m / (coord1.second - coord2.second + coord2.first - coord1.first);
            if (coord1.second - coord1.first > coord2.second - coord2.first){
                // 1 higher slope
                left[i].insert(make_pair(intersect, j));
                right[j].insert(make_pair(intersect, i));
            } else {
                right[i].insert(make_pair(intersect, j));       
                left[j].insert(make_pair(intersect, i));
         
            }
        }
    }

    for (int i = 0; i < n; i++){
        ull sum = 0;
        rightSum[i].insert(make_pair(-1, 0));
        for (pair<double, int> x : right[i]){
            sum += (ull)ridges[x.second].second;
            rightSum[i].insert(make_pair(x.first, sum));
        }

        vector<pair<double, int>> temp;
        for (pair<double, int> x : left[i]){
            temp.pb(make_pair(x.first, x.second));
        }
        reverse(temp.begin(), temp.end());
        sum = 0;
        for (pair<double, int> x : temp){
            sum += (ull)ridges[x.second].second;
            leftSum[i].insert(make_pair(x.first, sum));
        }
        leftSum[i].insert(make_pair(m + 1, 0));
    }

    for (int i = 0; i < q; i++){
        int p, l;
        cin >> p >> l;
        p--;
        double r = l * 1.0 + k;

        ull ans = (--rightSum[p].upper_bound(make_pair(r, 0)))->second;
        ans += (leftSum[p].upper_bound(make_pair(l + 1, 0)))->second;
        cout << ans << endl;
    }    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}