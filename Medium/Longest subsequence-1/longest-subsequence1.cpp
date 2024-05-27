//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
      int longestSubseq(int n, vector<int>& a) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int idx = n - 1; idx >= 0; --idx) {
            for (int parentIdx = -1; parentIdx < n; ++parentIdx) {
                int take = 0;
                if (parentIdx == -1 || abs(a[idx] - a[parentIdx]) == 1) {
                    take = 1 + dp[idx + 1][idx + 1];
                }

                int notake = dp[idx + 1][parentIdx + 1];

                dp[idx][parentIdx + 1] = max(take, notake);
            }
        }

        return dp[0][0];
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        vector<int> a(n);
        Array::input(a, n);

        Solution obj;
        int res = obj.longestSubseq(n, a);

        cout << res << endl;
    }
}

// } Driver Code Ends