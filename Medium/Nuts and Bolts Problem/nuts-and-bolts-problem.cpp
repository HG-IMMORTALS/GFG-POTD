//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    void matchPairs(int n, char nuts[], char bolts[]) {
          string s = "!#$%&*?@^";
        unordered_map<char, int> mp;
        for(int i = 0; i < s.size(); i++)
            mp[s[i]] = i;
        sort(nuts, nuts + n, [&](char ch1, char ch2) {
            return mp[ch1] < mp[ch2];
        });
        sort(bolts, bolts + n, [&](char ch1, char ch2) {
            return mp[ch1] < mp[ch2];
        });
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        char nuts[n], bolts[n];
        for (int i = 0; i < n; i++) {
            cin >> nuts[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> bolts[i];
        }
        Solution ob;
        ob.matchPairs(n, nuts, bolts);
        for (int i = 0; i < n; i++) {
            cout << nuts[i] << " ";
        }
        cout << "\n";
        for (int i = 0; i < n; i++) {
            cout << bolts[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends