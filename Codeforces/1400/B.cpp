#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int p, f;
        cin >> p >> f;
        int a, b;
        cin >> a >> b;
        int aw, bw;
        cin >> aw >> bw;

        if (bw > aw){
            swap(a, b);
            swap(aw, bw);
        }
        if (f > p){
            swap(f, p);
        }
        int mx = 0;
        for (int i = 0; i <= min<int>(b, floor(p/bw)); ++i){
            int capacityF = min<int>(b - i, floor(f/bw));
            int resultingP = p - i * bw;
            int resultingF = f - capacityF * bw;
            int canHoldF = min<int>(floor(resultingF/aw), a);
            int resultingA = a - canHoldF;
            int canHoldP = min<int>(floor(resultingP/aw), resultingA);
            mx = max<int>(mx, i + capacityF + canHoldF + canHoldP);
        }
        cout << mx << endl;
    }
    return 0;
}