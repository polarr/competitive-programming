/** Code by 1egend **/
#include <bits/stdc++.h>

using namespace std;

int main(){
    int l;
    cin >> l;
    if (l < 2){
        cout << -1 << endl;
        return 0;
    }
    vector <int> n;
    for (int i = 0; i < l; ++i){
        int z;
        cin >> z;
        n.push_back(z);
    }
    int ans = INT_MAX;
    for (int j = 0; j < n.size() - 1; ++j){
        for (int k = j + 1; k < n.size(); ++k){
            if (n[j] == n[k]){
                ans = min<int>(ans, k - j + 1);
                break;
            }
        }
    }
    cout << (ans == INT_MAX ? -1: ans);
    return 0;
}