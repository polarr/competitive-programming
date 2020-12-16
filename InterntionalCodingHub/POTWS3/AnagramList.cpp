/** Code by 1egend **/
#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;

void solve(){
    int x;
    cin >> x;
    vector <string> words;
    for (int i = 0; i < x; ++i){
        string z;
        cin >> z;
        words.push_back(z);
    }
    int ans = 0;
    while(words.size() > 0){
        string w1 = words[0];
        sort(w1.begin(), w1.end());
        for (int b = 1; b < words.size(); ++b){
            string w2 = words[b];
            sort(w2.begin(), w2.end());
            if (w1.compare(w2) == 0){
                words.erase(words.begin() + b);
                b--;
            }
        }
        words.erase(words.begin());
        ans ++;
    }
    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    // cout << "Case #" << t  << ": " << endl;
    solve();
    return 0;
}