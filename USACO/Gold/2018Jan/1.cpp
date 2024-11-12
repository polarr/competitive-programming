/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-11-08
 * Contest: USACO 2018 Jan Gold
 * Problem: 1
**/

#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

const string iofilename = "mootube";
ifstream fin(iofilename + ".in");
ofstream fout(iofilename + ".out");

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

        int componentSize(int x){
            return sizes[find(x)];
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

// Use fstream (fin, fout) instead of iostream!
void solve(){
    int n, q; fin >> n >> q;

    DSU disjoint(n);

    vector<tuple<ll, int, int>> edges;
    for (int i = 0; i < n - 1; i++){
        int p, q; ll r; fin >> p >> q >> r;
        --p; --q;
        edges.pb({r, p, q});
    }

    int e = 0;

    sort(edges.begin(), edges.end(), greater<>());

    vector<tuple<ll, int, int>> questions;

    for (int i = 0; i < q; i++){
        int k, v; fin >> k >> v;
        --v;
        questions.pb({k, v, i});
    }

    sort(questions.begin(), questions.end(), greater<>());

    vector<int> ans(q);
    for (int i = 0; i < q; i++){
        tuple<ll, int, int> question = questions[i];
        ll k = get<0>(question); int v = get<1>(question); int j = get<2>(question);

        while(e < n - 1 && get<0>(edges[e]) >= k){
            disjoint.unite(get<1>(edges[e]), get<2>(edges[e]));
            e++;
        }

        ans[j] = disjoint.componentSize(v) - 1;
    }
    
    for (int i = 0; i < q; i++){
        fout << ans[i] << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    solve();
    return 0;
}