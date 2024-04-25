//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int findMaxSum(int n, int m, vector<vector<int>> mat) {
           int maxi=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int sum=0;
                int cnt=0;
                if(i-1>=0 && j-1>=0)
                 cnt++;
                if(i-1>=0)
                 cnt++;
                if(i-1>=0 && j+1<m)
                 cnt++;
                if(i+1<n && j-1>=0)
                 cnt++;
                if(i+1<n)
                 cnt++;
                if(i+1<n && j+1<m)
                 cnt++;
            cnt++;
            if(cnt==7){
                sum+=mat[i-1][j-1]+mat[i-1][j]+mat[i-1][j+1]+mat[i][j]+mat[i+1][j-1]
                +mat[i+1][j]+mat[i+1][j+1];
            }
            maxi=max(maxi,sum);
            }
        }
        return maxi==0?-1:maxi;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, i, j;
        cin >> N >> M;
        vector<vector<int>> Mat(N, vector<int>(M));
        for (i = 0; i < N; i++)
            for (j = 0; j < M; j++) cin >> Mat[i][j];
        Solution ob;
        cout << ob.findMaxSum(N, M, Mat) << "\n";
    }
}
// } Driver Code Ends