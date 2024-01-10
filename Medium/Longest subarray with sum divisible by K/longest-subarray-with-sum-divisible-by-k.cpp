//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int longSubarrWthSumDivByK(int a[], int n, int k)
	{
	     int sum=0,maxi=0,j=0;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            sum+=a[i];
            int r=sum%k;
            if(r<0) r+=k;
            if(r==0) maxi=max(maxi,i+1);
            else{
                if(mp.find(r)!=mp.end()) maxi=max(maxi,i-mp[r]);
                else mp[r]=i;
            }
        }
        return maxi;
	}
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,k,i;
	cin>>n>>k; int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution ob;
	cout<<ob.longSubarrWthSumDivByK(arr, n, k)<<"\n";
	}
	return 0;	 
}

// } Driver Code Ends