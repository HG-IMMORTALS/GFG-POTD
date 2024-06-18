//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
     int baseLength(int n , int r){
        double nn = static_cast<double>(n);
        double rr = static_cast<double>(r);
        
        return static_cast<int>(2*sqrt(rr*rr-nn*nn/4));
    }
    
    int count =0;
    
    int rectanglesInCircle(int r) {
        // code here
        for(int i=1;i<2*r;i++){
            int currentBase = baseLength(i,r);
            for(int j=1;j<=currentBase;j++){
                count ++;
            }
        }
        return count;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        int ans = ob.rectanglesInCircle(n);
        cout << ans << "\n";
    }
}
// } Driver Code Ends