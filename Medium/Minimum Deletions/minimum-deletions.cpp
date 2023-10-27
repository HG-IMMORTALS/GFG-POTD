//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int minimumNumberOfDeletions(string S) { 
        string t=S;
        reverse(t.begin(),t.end());
        int n=S.length();
        
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(S[i-1]==t[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                    continue;
                }
                
                int a=dp[i-1][j];
                int b=dp[i][j-1];
                
                dp[i][j]=max(a,b);
            }
        }
        return n-dp[n][n];
    } 
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string S;
        cin >> S;
        Solution obj;
        cout << obj.minimumNumberOfDeletions(S) << endl;
    }
    return 0;
}
// } Driver Code Ends