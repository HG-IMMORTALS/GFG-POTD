//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    vector<int> printKClosest(vector<int> a, int n, int k, int x) {
           // code here
        map<int,vector<int>> u;
        sort(a.rbegin(),a.rend());
        for(int i=0;i<n;i++){
            if(x!=a[i]) u[abs(x-a[i])].push_back(a[i]);
        }
        vector<int> p;
        for(auto e:u){
            for(auto f:e.second){
                p.push_back(f);
                k--;
                if(k==0) return p; 
            }
        }
        return p;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, x;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> k >> x;
        Solution ob;
        auto ans = ob.printKClosest(arr, n, k, x);
        for (auto e : ans) {
            cout << e << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends