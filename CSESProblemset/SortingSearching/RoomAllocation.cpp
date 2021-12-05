/** Code by 1egend **/
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mt make_tuple
#define ull unsigned long long
const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;

void solve(){
    int n;
    cin >> n;
    vector<tuple<int, bool, int>> timeline;
    for (int i = 0; i < n; ++i){
        int a, b;
        cin >> a >> b;
        timeline.pb(mt(a, 0, i));
        timeline.pb(mt(b, 1, i));
    }
    sort(timeline.begin(), timeline.end());
    int overlap = 0;
    int maxRooms = 0;
    vector<int> ans(n);
    set<int> rooms;
    for (int i = 0; i < 2 * n; ++i){
        if (get<1>(timeline[i]) == 0){
            ++overlap;
            if (rooms.size() == 0){
                ans[get<2>(timeline[i])] = overlap;
                maxRooms = max<int>(maxRooms, overlap);
            }
            else{
                ans[get<2>(timeline[i])] = *rooms.begin();
                rooms.erase(rooms.begin());
            }
            continue;
        }

        --overlap;
        rooms.insert(ans[get<2>(timeline[i])]);
    }

    cout << maxRooms << endl;
    for (int i: ans){
        cout << i << " ";
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}	