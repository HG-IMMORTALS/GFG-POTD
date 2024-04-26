//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    
    vector<int> solve(int i, int j, vector<vector<int>>& matrix, int m, int n, int dir){
        if(matrix[i][j] == 0 && j == 0 && dir == 2){
            return {i, j};
        }
        
        if(matrix[i][j] == 0 && j == m-1 && dir == 0){
            return {i, j};
        }
        
        if(matrix[i][j] == 0 && i == 0 && dir == 3){
            return {i, j};
        }
        
        if(matrix[i][j] == 0 && i == n-1 && dir == 1){
            return {i, j};
        }
        
        if(matrix[i][j] == 1){
            matrix[i][j] = 0;
            return solve(i, j, matrix, m, n, (dir+1)%4);
        }
        
        if(dir == 0){
            return solve(i, j+1, matrix, m, n, dir);
        }
        
        if(dir == 1){
            return solve(i+1, j, matrix, m, n, dir);
        }
        
        if(dir == 2){
            return solve(i, j-1, matrix, m, n, dir);
        }
        
        if(dir == 3){
            return solve(i-1, j, matrix, m, n, dir);
        }
    }
    
    vector<int> FindExitPoint(int n, int m, vector<vector<int>>& matrix) {
        // Code here
        
        // dir == 0 -> move right
        // dir == 1 -> move down
        // dir == 2 -> move left
        // dir == 3 -> move up
        
        return solve(0, 0, matrix, m, n, 0);
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> matrix[i][j];
        Solution obj;
        vector<int> ans = obj.FindExitPoint(n, m, matrix);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends