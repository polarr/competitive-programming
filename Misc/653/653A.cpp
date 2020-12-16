#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    vector <int> x;
    while(t--){
        int z;
        cin >> z;
        x.push_back(z);
    }

    // O(n3)
    bool can = false;
    for (int a = 0; a < x.size() - 2; a++){
        for (int b = a + 1; b < x.size() - 1; b++){
            for (int c = b + 1; c < x.size(); c++){
                if (x[a] != x[b] && x[b] != x[c] && x[a] != x[c] && abs(x[a] - x[b]) <= 2 && abs(x[c] - x[b]) <= 2 && abs(x[a] - x[c]) <= 2){
                    can = true;
                }
            }
        }
    }

    cout << (can ? "YES":"NO");
    return 0;
}