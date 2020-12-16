/** Code by 1egend **/
#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;

// I am not going to use next_permutations() to go the easy route
vector <string> ans;
void recStrings(string prefix, string k){
    if (k.length() == 1){
        ans.push_back(prefix + k);
        return;
    }
    string distinctK = k;
    for (int i = 1; i < distinctK.length(); i++){
        if (distinctK[i] == distinctK[i - 1]){
            distinctK.erase(distinctK.begin() + i - 1);
            i--;
        }
    }
    for (int i = 0; i < distinctK.length(); i++){
        char added = distinctK[i];
        string newK = k;
        newK.erase(newK.begin() + newK.find(added));
        recStrings(prefix + added, newK);
    }
}

/** Alternate solution with set and no worries for having distinct K values.
 *  My current solution is probably slightly faster by a constant term 

set <string> ans;
void recStrings(string prefix, string k){
    if (k.length() == 1){
        ans.insert(prefix + k);
        return;
    }
    for (int i = 0; i < k.length(); i++){
        string newK = k;
        newK.erase(newK.begin() + i);
        recStrings(prefix + k[i], newK);
    }
}
**/
void solve(){
    string n;
    cin >> n;   
    sort(n.begin(), n.end());
    recStrings("", n);
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i){
        cout << ans[i] << endl;
    }
    /**
    for(auto i: ans){
        cout << i << endl;
    }
    **/
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    // cout << "Case #" << t  << ": " << endl;
    solve();
    return 0;
}