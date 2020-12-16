#include <bits/stdc++.h>
using namespace std;


int main() {
    int x;
    cin >> x;
    vector <int> k;
    for (int i = 0; i < x; ++i){
        int z;
        cin >> z;
        k.push_back(z);
    }
    int maxDiff = 0;
    int mx = 0;
    int mn = INT_MAX;
    for (int i = 0; i < x - 1; ++i){
        if (k[i] == -1){
            continue;
        }
        if (k[i + 1] != -1){
            maxDiff = max<int>(maxDiff, abs(k[i + 1] - k[i]));
            
        }
        if ((i > 0 && k[i - 1] == -1) || k[i + 1] == -1){
            mx = max<int>(k[i], mx);
            mn = min<int>(k[i], mn);
        }
    }
    cout << max<int>(maxDiff, mx - floor((mx + mn)/2));
    return 0;
}