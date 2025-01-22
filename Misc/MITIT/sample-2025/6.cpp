/**
 * Solution by 1egend (polarity.sh)
 * Date: 2025-01-18
 * Contest: MITIT sample-2025
 * Problem: 6
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

/** DS: Disjoint Set Union 
 *  PURPOSE: Dynamically updates connectedness of graph
 *  TIME: O(amortized(N))
*/
class DSU {
    private: 
        vector<int> parents;
        vector<int> sizes;
    
    public:
        int components;
        DSU(int size) : parents(size), sizes(size, 1){
            for (int i = 0; i < size; i++){
                parents[i] = i;
            }

            components = size;
        }

        int find(int x){
            return (parents[x] == x ? x : (parents[x] = find(parents[x])));
        }

        bool unite(int a, int b){
            int parentA = find(a);
            int parentB = find(b);
            if (parentA == parentB){
                return false;
            }

            components--;

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

/** ALGORITHM: Modular Exponentiation 
 *  PURPOSE: Computes x^n (mod m)
 *  CONSTRAINT: m * m <= LLONG_MAX to prevent overflow
 *  TIME: O(log n)
*/
ll mod_exp(ll x, ll n, ll m) {
	x %= m;

	ll res = 1;
	while (n > 0) {
		if (n % 2 == 1) { res = res * x % m; }
		x = x * x % m;
		n /= 2;
	}

	return res;
}

void solve(){
    int n; cin >> n;
    if (n == 2){
        cout << 2 << endl;
        return;
    }

    vector<vector<bool>> asked(n, vector<int>(n - 1, false));
    DSU edges(n * n);

    for (int i = 0; i < n * (n - 1)/2; i++){
        int a, b; cin >> a >> b;
        --a; --b;
        swap(a, b); // b > a
        asked[a][b] = true;
        for (int c = 0; c < n; c++){
            if (c == a || c == b){
                continue;
            }

            if (asked[max(a, c)][min(a, c)] && asked[max(b, c)][min(b, c)]){

            }
        }
    }


    cout << mod_exp(2, edges.components, MOD) << endl;

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}