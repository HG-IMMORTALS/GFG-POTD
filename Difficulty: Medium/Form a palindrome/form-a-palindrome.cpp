//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
      int solve(string str , int l , int h , vector<vector<int>>&dp){
     if (l >= h) {
            return 0;
        }
      
      if(dp[l][h] != -1){
          return dp[l][h];
      }
      
      if(str[l] == str[h]){
          dp[l][h] = solve(str , l+1 , h-1 , dp);
      }
      else{
          dp[l][h] = 1+min(solve(str , l+1 , h,dp) , solve(str , l , h-1 , dp));
      }
      return dp[l][h];
  }
    int countMin(string str){
      int n = str.length();
      vector<vector<int>>dp(n , vector<int>(n+1 , -1));
      return solve(str , 0 , n-1 , dp);
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}


// } Driver Code Ends