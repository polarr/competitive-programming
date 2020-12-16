#include <bits/stdc++.h>

using namespace std;

int mostFrequentCount(string arr, int n) 
{ 
    // Insert all elements in hash. 
    unordered_map<int, int> hash; 
    for (int i = 0; i < n; i++) 
        hash[arr[i]]++; 
  
    // find the max frequency 
    int max_count = 0, res = -1; 
    for (auto i : hash) { 
        if (max_count < i.second) { 
            res = i.first; 
            max_count = i.second; 
        } 
    } 
  
    return max_count; 
} 

int main(){
    int t;
    cin >> t;
    while(t--){
        string x;
        cin >> x;
        // Odd case
        int a = x.length() - mostFrequentCount(x, x.length());
        int b = 2 * 10e5 + 1;

        // Even case
        // order matters 
        for (int j = 0; j < 10; j++){
            for (int k = 0; k < 10; k++){
                if (j == k){
                    continue;
                }
                int total = 0;
                int rn = j;
                for (int i = 0; i < x.length(); i++){
                    if (x[i] - '0' == rn){
                        total ++;
                        rn = (rn == j ? k:j);
                    }
                }

                total = x.length() - (total % 2== 0 ? total: total - 1);
                b = min<int>(b, total);
            }
        }

        cout << min<int>(a, b) << endl;
    }
    return 0;
}