/**
 * Solution by 1egend (polarity.sh)
 * Date: 2024-03-18
 * Contest: USACO 2024 Open
 * Problem: Silver P1. Bessie's Interview
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

        bool allConnected(){
            return sizes[0] == sizes.size();
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
    int n, k;
    cin >> n >> k;

    DSU farmers(k);

    vector<ull> cow_times;

    for (int i = 0; i < n; i++){
        ull t;
        cin >> t;
        cow_times.pb(t);
    }

    ull time = 0;
    unordered_map<ull, vector<int>> farmer_times;
    set<ull> next_times;
    queue<int> waiting_farmers;
    for (int i = 0; i < k; i++){
        next_times.insert(cow_times[i]);
        farmer_times[cow_times[i]].pb(i);
    }

    bool doneFarmers = false;

    for (int i = k; i < n; i++){
        int farmer;
        if (!waiting_farmers.empty()){
            farmer = waiting_farmers.front();
            waiting_farmers.pop();
        } else {
            time = *next_times.begin();
            next_times.erase(next_times.begin());

            vector<int> now_farmers = farmer_times[time];
            farmer = now_farmers[0];
            for (int j = 1; j < now_farmers.size(); j++){
                waiting_farmers.push(now_farmers[j]);
            }

            if (!doneFarmers){
                for (int j = 1; j < now_farmers.size(); j++){
                    farmers.unite(farmer, now_farmers[j]);
                }
            }

            if (farmers.allConnected()){
                doneFarmers = true;
            }
        }

        ull next_time = time + cow_times[i];
        next_times.insert(next_time);
        farmer_times[next_time].pb(farmer);
    }

    int farmer;
    if (!waiting_farmers.empty()){
        farmer = waiting_farmers.front();
    } else {
        time = *next_times.begin();
        next_times.erase(next_times.begin());

        vector<int> now_farmers = farmer_times[time];
        farmer = now_farmers[0];

        if (!doneFarmers){
            for (int j = 1; j < now_farmers.size(); j++){
                farmers.unite(farmer, now_farmers[j]);
            }
        }
    }

    cout << time << endl;
    string ans = "";

    for (int i = 0; i < k; i++){
        ans += (farmers.connected(farmer, i) ? "1":"0");
    }

    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}