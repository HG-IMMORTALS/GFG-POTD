//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	// #define ll long long
	ll countStrings(int n) {
      ll a = 2;
          ll b = 3;
          ll c = a + b;
 
            if (n == 1) return 2;
            else if (n == 2) return 3;
            else {
                for (int i = 3; i <= n-1; i++) {
                    a = b;
                    b = c;
                    c = (a + b) % (ll)(1e9 + 7);
                }
            }
      return c;
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
        auto ans = ob.countStrings(n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends