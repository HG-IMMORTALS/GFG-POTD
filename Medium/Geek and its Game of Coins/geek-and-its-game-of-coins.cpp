//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
      int f(int n, int x, int y, vector<int> &dp){
        if(n==0) return 0;
        
        if(dp[n]!=-1) return dp[n];

        int p1 = 0, p2 = 0, p3 = 0;
        if(n>=x) p1 = 1+f(n-x, x, y, dp);
        if(n>=y) p2 = 1+f(n-y, x, y, dp);
        p3 = 1+f(n-1, x, y, dp);
        
        if(p1%2==1 || p2%2==1 || p3%2==1) return dp[n] = 1;
        return dp[n] = 0;
    }
  
    int findWinner(int n, int x, int y) {
        // Tabulation
        vector<int> dp(n+1, 0);
        
        for(int i=1; i<=n; i++){
            int p1 = 0, p2 = 0, p3 = 0;
            if(i>=x) p1 = 1+dp[i-x];
            if(i>=y) p2 = 1+dp[i-y];
            p3 = 1+dp[i-1];
            
            if(p1%2==1 || p2%2==1 || p3%2==1) dp[i] = 1;
            else dp[i] = 0;
        }
        
        return dp[n];
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int x;
        scanf("%d", &x);

        int y;
        scanf("%d", &y);

        Solution obj;
        int res = obj.findWinner(n, x, y);

        cout << res << endl;
    }
}

// } Driver Code Ends