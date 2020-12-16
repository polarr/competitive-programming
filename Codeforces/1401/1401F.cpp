#include <bits/stdc++.h>

using namespace std;

void replace(vector <int> &arr, int x, int k){
    arr[x] = k;
}
void reverse(vector <int> &arr, int k){
    for (int i = 0; i < arr.size(); i+= pow(2, k)){
        reverse(arr.begin() + i, arr.begin() + i + pow(2, k));
    }
}
void swap(vector <int> &arr, int k){
    for (int i = 0; i < arr.size(); i+= 2 * pow(2, k)){
        for (int n = 0; n < pow(2, k); ++n){
            swap(arr[i + n], arr[i + n + pow(2, k)]);
        }
    }
}
int sum(vector <int> arr, int l, int r){
    int ans = 0;
    for (int i = l -1; i < r; ++i){
        ans += arr[i];
    }
    return ans;
}
int main(){
    int n, k;
    vector <int> x;
    for (int i = 0; i < pow(2,n); ++i){
        int z;
        cin >> z;
        x.push_back(z);
    }

    while(k--){
        int m;
        cin >> m;
        int a, b;
        switch(m){
            case 1:
                cin >> a >> b;
                replace(x, a, b);
            break;
            case 2:
                cin >> a;
                reverse(x, a);
            break;
            case 3:
                cin >> a;
                swap(x, a);
            break;
            case 4:
                cin >> a >> b;
                cout << sum(x, a, b) << endl;
            break;
        }
    }
    return 0;
}