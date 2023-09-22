//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    vector<int> find(int arr[], int n , int x )
    {
        vector<int>vec;
         int l=0,h=n-1;
         while(l<=h)
         {
             if(arr[l]!=x) l++;
             if(arr[h]!=x) h--;
             if(arr[l]==x && arr[h]==x)
             {
                 vec.push_back(l);
                 vec.push_back(h);
                 break;
             }
         }
         if(l>h)
         {
             vec.push_back(-1);
             vec.push_back(-1);
         }
         return vec;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends