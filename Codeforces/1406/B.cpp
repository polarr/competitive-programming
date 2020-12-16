/** Code by 1egend **/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int x;
        cin >> x;
        vector <int> negatives;
        vector <int> positives;
        bool hasZero = false;
        for (int i = 0; i < x; ++i){
            int k;
            cin >> k;
            if (k < 0){
                negatives.push_back(k);
            }
            else if (k > 0){
                positives.push_back(k);
            }
            else{
                hasZero = true;
            }
        }
        ll ans = LLONG_MIN;
        sort(negatives.begin(), negatives.end());
        sort(positives.begin(), positives.end());
        if (positives.size() + negatives.size() < 5){
            cout << 0 << endl;
            continue;
        }
        if (positives.size() == 0){
            ans = 1;
            for (int i = negatives.size() - 5; i < negatives.size(); ++i){
                ans *= negatives[i];
            }
        }
        else if (negatives.size() < 2){
            ans = 1;
            for (int i = max<int>(0, positives.size() - 5); i < positives.size(); ++i){
                ans *= positives[i];
            }
            ans *= negatives.size() == 1 ? negatives[0]: 1;
        }
        else{
            for (int i = max<int>(0, ((5 - positives.size()) % 2 == 0 ? 5 - positives.size(): 5 - positives.size() + 1)); i <= min<int>(4, negatives.size()); i += 2){
                int pos = 5 - i;
                ll curr = 1;
                for (int a = 0; a < i; ++a){
                    curr *= negatives[a];
                }
                for (int b = positives.size() - pos; b < positives.size(); ++b){
                    curr *= positives[b];
                }
                ans = max<ll>(ans, curr);
            }
        }
        cout << max<ll>(ans, (hasZero ? 0: ans)) << endl;
    }
    return 0;
}
