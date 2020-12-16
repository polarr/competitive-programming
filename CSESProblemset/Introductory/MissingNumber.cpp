#include <bits/stdc++.h>

using namespace std;

int main(){
    int l;
    cin >> l;
    vector <int> k;
    for (int i = 0; i < l - 1; ++i){
        int x;
        cin >> x;
        k.push_back(x);
    }

    sort(k.begin(), k.end());
    for (int i = 0; i < k.size(); ++i){
        if (k[i] != i + 1){
            cout << i + 1;
            return 0;
        }
    }
    cout << l;
    return 0;
}