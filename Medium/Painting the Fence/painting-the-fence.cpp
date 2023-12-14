//{ Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

// } Driver Code Ends
#define ll long long
int mod=1e9+7;
class Solution{
    public:
    long long countWays(int n, int k)
    {
        ll dp[n+1];
        dp[0] = 0;
        dp[1] = k;
        dp[2] = static_cast<long long>(k)*k;
        for(int i=3;i<=n;i++)
        {
            dp[i] = ((k-1)*(dp[i-1] + dp[i-2]))%mod;
        }
        return dp[n];
    }
};

//{ Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}
// } Driver Code Ends