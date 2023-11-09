//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    /*Function to count zeros in each column
    * N : Number of rows and columns in array
    M is the matrix that is globally declared
    */
    int columnWithMaxZeros(vector<vector<int>>arr,int N){
        // int ans=0;
        // int idx=0;
        // for(int i=0;i<N;i++)
        // {
        //     int cnt=0;
        //     for(int j=0;j<N;j++)
        //     {
        //         if(arr[j][i]==0) cnt++;
        //     }
        // if(cnt>ans) idx=i;
        // ans=max(ans,cnt);
        // }
        // return idx;
        int col=-1,maxi=0;
        for(int j=0;j<N;j++)
        {
            int c=0;
            for(int i=0;i<N;i++)
            {
                if(arr[i][j]==0) c++;
            }
            if(c>maxi)
            {
                maxi=c;
                col=j;
            }
        }
        return col;
    }
};

//{ Driver Code Starts.
int main() {
	
	int testcase;
	
	cin >> testcase;
	
	while(testcase--){
	    int N;
	    cin >> N;
	    vector<vector<int>>arr(N,vector<int>(N));
	    // Taking elements input into the matrix
	    for(int i = 0;i<N;i++){
	        for(int j = 0;j<N;j++){
	            int x;
	            cin >> x; 
	            arr[i][j]=x;
	        }
	    }
	    Solution ob;
	    cout << ob.columnWithMaxZeros(arr,N) << endl;
	}
	
	return 0;
}
// } Driver Code Ends