//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    long countSubarrays(int arr[], int n, int L, int R)
    {
        int j=n;
        long ans=0;
        int k=n;
        int i=n-1;
        while(i>=0){
            if(arr[i]>=L && arr[i]<=R){
                ans+=j-i;
                k=i;
            }
            else{
                if(arr[i]>R){
                    // kuch nhi
                    j=i;
                    k=i;
                }
                else
                ans+=j-k;
            }
            i--;
        }
        return ans;
    }
};

//{ Driver Code Starts.
// driver program
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        
        int n ,l,r;
        cin >> n>>l>>r;
        int a[n];
        for(int i=0;i<n;i++)
        cin >> a[i];
        Solution ob;
    	cout << ob.countSubarrays(a, n, l, r)<<endl;
    }
	return 0;
}

// } Driver Code Ends