/** Code by 1egend **/
#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;

// A utility function to get max of two integers 
int max (int x, int y) { return (x > y)? x : y; } 
  
// Returns the length of the longest palindromic subsequence in seq 
int solve(char *seq, int i, int j) 
{ 
// Base Case 1: If there is only 1 character 
if (i == j) 
    return 1; 
  
// Base Case 2: If there are only 2  
// characters and both are same 
if (seq[i] == seq[j] && i + 1 == j) 
    return 2; 
  
// If the first and last characters match 
if (seq[i] == seq[j]) 
    return lps (seq, i+1, j-1) + 2; 
  
// If the first and last characters do not match 
return max( lps(seq, i, j-1), lps(seq, i+1, j) ); 
} 

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string s;
    cin >> s;

    cout << solve(s, 0, s.length() - 1);
    return 0;
}	