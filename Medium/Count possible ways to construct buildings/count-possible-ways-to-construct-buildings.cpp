//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	long long mod=1e9+7;
	int TotalWays(int N)
	{
	     long long int b = 1, e = 1;
	    
	    for(int i = 1;i<N;i++){
	        long long int temp = b;
	        b = e;
	        e = e + temp;
	        b = b%mod;
	        e = e%mod;
	    }
	    return ((b%mod+e%mod)%mod*(b%mod+e%mod)%mod)%mod;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends