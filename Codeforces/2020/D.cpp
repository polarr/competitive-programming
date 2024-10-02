/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-09-29
 * Contest: Codeforces 2020
 * Problem: D
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

class DSU {
    private: 
        vector<int> parents;
        vector<int> sizes;
    
    public:
        DSU(int size) : parents(size), sizes(size, 1){
            for (int i = 0; i < size; i++){
                parents[i] = i;
            }
        }

        int find(int x){
            return (parents[x] == x ? x : (parents[x] = find(parents[x])));
        }

        int componentCount(){
            int ans = 0;
            for (int i = 0; i < parents.size(); i++){
                if (parents[i] == i){
                    ans++;
                    //cout << i << endl;
                }
            }

            return ans;
        }

        bool unite(int a, int b){
            int parentA = find(a);
            int parentB = find(b);
            if (parentA == parentB){
                return false;
            }

            if (sizes[parentA] > sizes[parentB]){
                swap(parentA, parentB);
            }

            sizes[parentB] += sizes[parentA];
            parents[parentA] = parentB;
            return true;
        }

        bool connected(int a, int b){
            return find(a) == find(b);
        }
};

void solve(){
    int n, m; cin >> n >> m;
    vector<tuple<int, int, int>> arr;
    vector<int> points(n, -1);
    DSU disjoint(m);

    for (int i = 0; i < m; i++){
        int a, d, k;
        cin >> a >> d >> k;
        
        arr.pb(tuple<int, int, int>{a - 1, d, k});
    }

    sort(arr.begin(), arr.end());
    for (int i = 0; i < m; i++){
        tuple<int, int, int> curr = arr[i];
        int endp = get<0>(curr) + get<1>(curr) * get<2>(curr);
        for (int point = get<0>(curr); point <= endp; point += get<1>(curr)){
            if (points[point] != -1){
                disjoint.unite(i, points[point]);
            } else {
                points[point] = i;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++){
        if (points[i] == -1){
            ans++;
        }
    }
    
    cout << ans + disjoint.componentCount() << endl;
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