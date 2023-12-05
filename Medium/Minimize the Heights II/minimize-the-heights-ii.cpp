//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
         sort(arr,arr+n);
       int diff=arr[n-1]-arr[0];
       
       int least,most,mini,maxi;
       least=arr[0]+k;
       most=arr[n-1]-k;
       
       for(int i=0;i<n-1;i++){
           mini=min(arr[i+1]-k,least);
           maxi=max(arr[i]+k,most);
           
           if(mini<0)
               continue;
           else 
               diff=min(diff,maxi-mini);
       }
       return diff;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends