//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    pair<int, int> kadne(vector<int>& v)
    {
        int sum = 0;
        int maxi = -1e9;  // Initialize maximum sum to a very small value
        int l = 0;        // Initialize left index of the maximum sum subarray
        int r = -1;       // Initialize right index of the maximum sum subarray
    
        int s = 0;        // Initialize the start index of the current subarray
        for (int i = 0; i < v.size(); i++)
        {
            sum += v[i];   // Add the current element to the running sum
    
            // If the current sum is greater than the maximum sum, update maximum sum and indices
            if (sum > maxi)
            {
                maxi = sum;
                l = s;
                r = i;
            }
    
            // If the current sum becomes negative, reset sum and update the start index
            if (sum < 0)
            {
                sum = 0;
                s = i + 1;
            }
        }
    
        // Return the pair of indices representing the maximum sum subarray
        return {l, r};
    }
    
    vector<vector<int>> sumZeroMatrix(vector<vector<int>> a)
    {
        int m = a.size();  // Number of rows in the matrix
        int n = a[0].size();  // Number of columns in the matrix
    
        int left, right, up, down;
        left = right = up = down = 0;
    
        // Iterate over all possible submatrices
        for (int i = 0; i < n; i++)
        {
            vector<int> arr(m, 0);
    
            for (int j = i; j < n; j++)
            {
                // Calculate the cumulative sum of the submatrix in the 'arr' vector
                for (int k = 0; k < m; k++)
                {
                    arr[k] += a[k][j];
                }
    
                unordered_map<long long, int> map;
                map[0] = -1;
    
                int l = 0, r = 0;
                long long sum = 0;
    
                // Use Kadane's algorithm to find the subarray with the maximum sum
                for (int k = 0; k < m; k++)
                {
                    sum += arr[k];
    
                    // Update the subarray indices when a zero-sum subarray is found
                    if (map.count(sum))
                    {
                        if ((k - map[sum]) > (r - l))
                        {
                            l = map[sum] + 1;
                            r = k + 1;
                        }
                    }
                    else
                    {
                        map[sum] = k;
                    }
                }
    
                // Update the maximum submatrix indices
                if ((j - i + 1) * (r - l) > (right - left) * (down - up))
                {
                    up = l;
                    down = r;
                    left = i;
                    right = j + 1;
                }
            }
        }
    
        // Extract the maximum submatrix and return it
        vector<vector<int>> result;
    
        for (int i = up; i < down; i++)
        {
            vector<int> arr;
    
            for (int j = left; j < right; j++)
            {
                arr.push_back(a[i][j]);
            }
    
            result.push_back(arr);
        }
    
        return result;
    }
  
};


//{ Driver Code Starts.




int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        
        vector<vector<int>> a(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>a[i][j];
            }
        }
        Solution ob;
        vector<vector<int>> ans = ob.sumZeroMatrix(a);
        if(ans.size() == 0){
            cout<<-1<<endl;
        }
        else{
            for(int i=0;i<ans.size();i++){
                for(int j=0;j<ans[0].size();j++){
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
        }
    }
    return 0;
}
// } Driver Code Ends