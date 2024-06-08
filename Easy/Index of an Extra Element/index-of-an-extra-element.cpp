//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int findExtra(int n, int arr1[], int arr2[]) {
            map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[arr1[i]]++;
            mp[arr2[i]]--;
        }
        int sol;
        for(auto it:mp)
        {
            if(it.second==1) sol=it.first;
        }
        auto it=find(arr1,arr1+n,sol);
        int index=0;
        if (it!=arr1+n)  
        { 
            index=it-arr1; 
        } 
        return index;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr1[n], arr2[n - 1];
        for (int i = 0; i < n; i++) {
            cin >> arr1[i];
        }
        for (int i = 0; i < n - 1; i++) {
            cin >> arr2[i];
        }
        Solution obj;
        cout << obj.findExtra(n, arr1, arr2) << endl;
    }
}
// } Driver Code Ends