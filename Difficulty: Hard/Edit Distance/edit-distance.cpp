//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int editDistance(string str1, string str2) {
         int n = str1.size(), m = str2.size(), dp[101][101];
        for ( int i = 0; i<101; i++ ){
            for ( int j = 0; j<101; j++ ) dp[i][j] = INT_MAX;
        }
        for ( int j = 0; j<m; j++ ) dp[n][j] = m-j; 
        for ( int i = 0; i<n; i++ ) dp[i][m] = n-i;
        dp[n][m] = 0;
        for ( int i = n-1; i>=0; i-- ){
            for ( int j = m-1; j>=0; j-- ){
                if ( str1[i] == str2[j] ) dp[i][j] = dp[i+1][j+1];
                else dp[i][j] = min({dp[i][j], 1 + dp[i+1][j], 1 + dp[i][j+1], 1 + dp[i+1][j+1] });
            }
        } return dp[0][0];
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends