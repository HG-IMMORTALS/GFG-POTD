//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> antiDiagonalPattern(vector<vector<int>> matrix) 
    {
         int n=matrix.size();
        int m=matrix[0].size();
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            ans.push_back(matrix[0][i]);
            int nr=0+1;
            int nc=i-1;
            while(nr<n && nc>=0)
            {
                ans.push_back(matrix[nr][nc]);
                nr=nr+1;
                nc=nc-1;
            }
        }
        for(int i=1;i<m;i++)
        {
            ans.push_back(matrix[i][m-1]);
            int nr=i+1;
            int nc=m-1-1;
            while(nr<n && nc>=0)
            {
                ans.push_back(matrix[nr][nc]);
                nr=nr+1;
                nc=nc-1;
            }
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
        vector<vector<int>> matrix;
        matrix.resize(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> ans = ob.antiDiagonalPattern(matrix);
        for (int i = 0; i < ans.size(); ++i) cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends