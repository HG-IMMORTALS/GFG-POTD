//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string removeKdigits(string s, int k) {
        int n=s.size();
        int x=0;
        for(int i=0;i<n;i++){
            if(x==k){
                break;
            }
            if(s[i]>s[i+1]){
                s.erase(s.begin()+i);
                x++;
                i=i-2;
            }
        }
        n=s.size();
        int len=0;
        for(int i=0;i<n;i++){
            if(s[i]!='0'){
                break;
            }
            len++;
        }
        s.erase(0,len);
        if(s.empty()) return "0";
        return s;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        int K;
        cin >> K;
        Solution obj;
        cout << obj.removeKdigits(S, K) << endl;
    }
    return 0;
}

// } Driver Code Ends