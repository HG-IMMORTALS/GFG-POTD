//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  int findUpperBound(const vector<int>& b, int value) {
        int low = 0;
        int high = b.size();
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (b[mid] <= value) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low; // returns the index of the first element greater than 'value'
    }

    vector<int> countElements(vector<int>& a, vector<int>& b, int n, vector<int>& query, int q) {
        vector<int> res;
        sort(b.begin(), b.end()); // Sort b to use binary search
        for (int i = 0; i < q; i++) {
            // Use the manual upper bound function
            int idx = findUpperBound(b, a[query[i]]);
            res.push_back(idx);
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
        cin >> n;
        vector<int> a, b, ans;
        int input;
        for (int i = 0; i < n; i++) {
            cin >> input;
            a.push_back(input);
        }
        for (int i = 0; i < n; i++) {
            cin >> input;
            b.push_back(input);
        }
        int q;
        cin >> q;
        vector<int> query;
        for (int i = 0; i < q; i++) {
            cin >> input;
            query.push_back(input);
        }
        Solution obj;
        ans = obj.countElements(a, b, n, query, q);
        for (int i = 0; i < q; i++) {
            cout << ans[i] << endl;
        }
    }
    return 0;
}
// } Driver Code Ends