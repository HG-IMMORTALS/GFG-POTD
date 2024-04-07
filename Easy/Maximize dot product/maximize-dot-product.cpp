//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		
	public:
int solve(int ind1,int ind2, int a[],int b[],vector<vector<int>> &dp ){
        
        if(ind1<0 && ind2>=0) return -1e9;
        if(ind2<0) return 0;
        
        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        
        int not_take= solve(ind1-1,ind2,a,b,dp);
        int take= a[ind1]*b[ind2]+solve(ind1-1,ind2-1,a,b,dp);
        
        return dp[ind1][ind2]= max(take,not_take);
    }
    int maxDotProduct(int n, int m, int a[], int b[]) 
    { 
      
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return solve(n-1,m-1,a,b,dp);
        
        // Your code goes here
    } 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        int a[n], b[m];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

        for(int i = 0; i < m; i++)
        	cin >> b[i];

       

	    Solution ob;
	    cout << ob.maxDotProduct(n, m, a, b) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends