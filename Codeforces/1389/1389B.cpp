#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int x;
        int y;
        int z;
        cin >> x >> y >> z;
        vector <int> arr;
        while(x--){
            int k;
            cin >> k;
            arr.push_back(k);
        }

        int mx = 0;
        for (int left = 0; left <= z; left ++){
            int s = 0;
            int mxint = 0;
            for (int i = 0; i <= y - 2 * left; i++){
                s += arr[i];
                if(i < arr.size() - 1){
                    mxint = max<int>(mxint, arr[i] + arr[i + 1]);
                }
            }
            s += mxint * left;

            mx = max<int>(mx, s);
        }

        cout << mx << endl;
    }
    return 0;
}