#include <bits/stdc++.h>

using namespace std;

int findNum (vector <int> arr, int num){
    for (int i = 0; i < arr.size(); ++i){
        if (arr[i] == num){
            return i;
        }
    }
    return -1;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int x;
        cin >> x;
        vector <int> a;
        for (int i = 0; i < x; ++i){
            int z;
            cin >> z;
            a.push_back(z);
        }
        vector <int> arr = a;
        bool found = false;
        for (int i = x; i > 0; --i){
            int s = findNum(a, i);
            if (s > 0 && s < a.size() - 1){
                cout << "YES" << endl << findNum(arr, i) << " " << findNum(arr, i) + 1 << " " << findNum(arr, i) + 2 << endl;
                found = true;
                break;
            }

            a.erase(a.begin() + s);
        }
        if (found){
            continue;
        }
    
        cout << "NO" << endl;
    }
    return 0;
}