//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int firstElement(int n) {
        long long mod = 1000000007;
        int fib = 1;
        int f0 = 1, f1 = 1;
        for(int i = 2; i<n; i++){
            fib = (f0 % mod + f1 % mod) % mod;
            f0 = f1;
            f1 = fib;
        }
        return fib % mod;
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
        cout << ob.firstElement(n) << endl;
    }
    return 0;
}

// } Driver Code Ends