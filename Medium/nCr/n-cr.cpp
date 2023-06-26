//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int nCr(int n, int r){
        // code here
         int modd=1e9+7;
        if(r>n)
        return 0;
        else if(r==n)
        return 1;
       int dp[n+1][r+1];
       for(int i=0;i<n+1;i++){
           for(int j=0;j<r+1;j++){
               if(i==j||i==0||j==0)
               dp[i][j]=1;
               else
               dp[i][j]=(dp[i-1][j]+dp[i-1][j-1])%modd;
           }
       }
       return dp[n][r];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}
// } Driver Code Ends