/** Code by 1egend **/
#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int x, y;
    cin >> x >> y;
    vector <pair<int, int>> a;
    vector <pair <int, int>> b;
    vector <pair <int, int>> ans;
    for (int i = 0; i < x; ++i){
        int j, k;
        cin >> j >> k;
        a.push_back(make_pair(j, k));
    }
    for (int i = 0; i < y; ++i){
        int j, k;
        cin >> j >> k;
        b.push_back(make_pair(j, k));
    }
    int start = 0;
    for (int i = 0; i < a.size(); ++i){
        pair <int, int> n = a[i];
        for (int j = start; j < b.size(); ++j){
            pair <int, int> k = b[j];
            if (n.second >= k.first && n.first <= k.second){
                ans.push_back(make_pair(max<int>(n.first, k.first), min<int>(n.second, k.second)));
                if (n.second >= k.second){
                    start = j + 1; 
                }
                else{
                    break;
                }
            }
        }
    }
    for (int i = 0; i < ans.size(); ++i){
        cout << ans[i].first << " " << ans[i].second << endl;
    }
    return 0;
}
