//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long int findMaxProduct(vector<int>& arr) {
        // Write your code here
      const long long int MOD = 1000000007;
      long long int n=arr.size();
      long long int prod=1;
      long long int cnt=0;
      long long int cntp=0;
      long long int cnt0=0;
      int maxi=INT_MIN;
           for(int i=0;i<n;i++){
              if(arr[i]<0){
                 maxi=max(maxi,arr[i])%MOD;
                 cnt++;
               }
               if(arr[i]!=0) prod=(prod*arr[i])%MOD;
               if(arr[i]>0) cntp++;
               if(arr[i]==0) cnt0++;
           }
           if(cnt0==arr.size()) return 0;
           if(cnt==1 && cntp==0 &&cnt0>0) return 0;
           if(cnt==1 && cntp==0 && cnt0==0 ) return arr[0]%MOD;
           if(cnt%2==0) return prod%MOD;
       return (prod/maxi)%MOD;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        long long int ans = ob.findMaxProduct(arr);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends