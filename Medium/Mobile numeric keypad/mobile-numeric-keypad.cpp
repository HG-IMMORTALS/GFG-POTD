//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long long dp[10][30];
    long long countsequence(int start,int len,vector<vector<int>> &moves)
    {
        if(len==1)
        return 1;
        
        if(dp[start][len]!=-1)
            return dp[start][len];
            
        long long ans=0;
        for(int i=0;i<moves[start].size();i++)
        {
           ans+=countsequence(moves[start][i],len-1,moves);
        }
        dp[start][len]=ans;
        return ans;
    }
    long long getCount(int n) {
        // Your code goes here
        vector<vector<int>> moves={{0,8},{1,2,4},{2,1,3,5},{3,2,6},
        {4,1,5,7},{5,2,4,6,8},{6,3,5,9},{7,4,8},{8,5,7,9,0},{9,6,8}};
        
        for(int i=0;i<10;i++)
        {
            for(int j=0;j<30;j++)
                dp[i][j]=-1;
        }
        
        long long ans=0;
        for(int i=0;i<10;i++)
        {
            ans+=countsequence(i,n,moves);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        cout << ob.getCount(n) << "\n";
    }
    return 0;
}

// } Driver Code Ends