/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-12-13
 * Contest: USACO 2024 December Silver
 * Problem: 3
**/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ull unsigned long long
#define ll long long

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;

vector<pair<int, int>> cardinal = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};

int n, q;
int ans;
vector<vector<int>> path;
vector<vector<int>> taken;

class DSU {    
    public:
        vector<int> parents;
        vector<int> sizes;
        DSU(int size) : parents(size), sizes(size, 1){
            for (int i = 0; i < size; i++){
                parents[i] = i;
            }
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


void trace_path(int r, int c, int sr, int sc, bool start){

    if (!start && r == sr && c == sc){
        return;
    }

    path[r][c] = 1;
    pair<int, int> nx = cardinal[taken[r][c] - 1];
    trace_path(r + nx.first, c + nx.second, sr, sc, false);
}

bool isGood = false;

void floodfill(int r, int c, bool turnBad){
    if (r < 0 || r > n - 1 || c < 0 || c > n - 1){
        isGood = true;
        return;
    }
    if (path[r][c]){
        return;
    }
    if (turnBad){
        path[r][c] = 1;
        ans--;
    }
    for (pair<int, int> card: cardinal){
        floodfill(r + card.first, c + card.second, turnBad);
    }
}

void solve(){
    cin >> n >> q;
    ans = n * n;

    DSU disjoint = DSU(n * n + 1);
    taken = vector<vector<int>>(n, vector<int>(n, 0));
    path = vector<vector<int>>(n, vector<int>(n, 0));

    for (int i = 0; i < q; i++){
        int r, c; char t; cin >> r >> c >> t;
        --r; --c;

        int index = r * n + c;
        int nx = 0;

        if (path[r][c] != 0){
            continue;
        }
        
        if (t == 'L'){
            taken[r][c] = 1;
            nx = r * n + c - 1;
            if (c == 0){
                nx = n * n;
            }
        } else if (t == 'R'){
            taken[r][c] = 2;
            nx = r * n + c + 1;
            if (c == n - 1){
                nx = n * n;
            }
        } else if (t == 'D'){
            taken[r][c] = 3;
            nx = (r + 1) * n + c;
            if (r == n - 1){
                nx = n * n;
            }
        } else if (t == 'U'){
            taken[r][c] = 4;
            nx = (r - 1) * n + c;
            if (r == 0){
                nx = n * n;
            }
        }

        if (nx != n * n && path[nx/n][nx % n] == 1){
            // connected to bad loop
            ans -= disjoint.sizes[disjoint.find(index)];
            disjoint.unite(index, nx);

            for (int y = 0; y < n; y++){
                for (int x = 0; x < n; x++){
                    if (path[y][x]){
                        continue;
                    }

                    isGood = false;
                    floodfill(y, x, false);
                    if (!isGood){
                        floodfill(y, x, true);
                    }
                }
            }

            continue;
        }

        if (disjoint.connected(index, nx)){
            // bad loop
            ans -= disjoint.sizes[disjoint.find(index)];
            trace_path(r, c, r, c, true);

            
        }

        disjoint.unite(index, nx);

        cout << ans << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    solve();
    return 0;
}