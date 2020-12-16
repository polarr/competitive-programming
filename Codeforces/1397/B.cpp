#include <bits/stdc++.h>

using namespace std;

inline float logb(int base, int x){
    return log(x)/log(base);
}
int main(){
    int x;
    cin >> x;
    vector <int> n; 
    for (int i = 0; i < x; ++i){
        int t;
        cin >> t;
        n.push_back(t);
    }
    sort(n.begin(), n.end());
    int i = 1;
    float npow = pow(n[x-1], 1.0/(x-1));
    cout << npow << endl;
    int power = abs(pow(floor(npow), x-1) - n[x-1]) > abs(pow(ceil(npow), x-1) - n[x-1]) ? ceil(npow): floor(npow);
    cout << power << endl;
    unsigned long long cost = 0;
    for (int z = 0; z < x; z++){
        cost += abs(n[z] - pow(power, z));
    }
    cout << cost;
    return 0;
}