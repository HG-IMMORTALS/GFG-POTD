//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
      set<vector<int>> ans;
    void solve(int ind,int n,int sum,vector<int> &arr,vector<int> &temp){
        if(sum==0){
            ans.insert(temp);
            return;
        }
        if(sum<0 || ind==n) return ;
        
        temp.push_back(arr[ind]);
        solve(ind+1,n,sum-arr[ind],arr,temp);
        temp.pop_back();
        
        solve(ind+1,n,sum,arr,temp);
    }
    vector<vector<int>> CombinationSum2(vector<int> arr,int n,int k)
    {
        //code here
        sort(arr.begin(),arr.end());
        vector<int> temp;
        solve(0,n,k,arr,temp);
        
        vector<vector<int>> sol;
        for(auto it:ans) sol.push_back(it);
        return sol;
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
        vector<int> arr(n);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        auto obj=ob.CombinationSum2(arr,n,k);
        for(int i=0;i<obj.size();i++)
        {
            for(int j=0;j<obj[i].size();j++)
            {
                cout<<obj[i][j]<<" ";
            }
            cout<<"\n";
        }
        if(obj.size()==0) cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends