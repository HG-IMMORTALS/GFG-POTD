//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    set<vector<int>> st;
    void solve(vector<int> &arr ,int n,int i){
        if(i == n){
            st.insert(arr);
            return;
        }
        for(int j = i; j<n; j++){
            swap(arr[i],arr[j]);
            solve(arr,n,i+1);
            swap(arr[i],arr[j]);
        }
    }
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
           solve(arr,n,0);
        vector<vector<int>> res;
        for(auto j:st){
            res.push_back(j);
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;
        vector<int> arr(n);
        
        for(int i=0 ; i<n ; i++)
            cin>>arr[i];

        Solution ob;
        vector<vector<int>> res = ob.uniquePerms(arr,n);
        for(int i=0; i<res.size(); i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<res[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends