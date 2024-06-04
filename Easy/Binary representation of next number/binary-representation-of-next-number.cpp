//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string binaryNextNumber(string s) {
           int n=s.size();
        string ans;
        int i=n-1;
        int f=0;
        for(;i>=0;i--){
            if(s[i]=='0'){
              s[i]='1';
              f=1;
              break;
            }
            else
             s[i]='0';
        }
        if(f==0){
            ans.push_back('1');
            for(int i=0;i<n;i++){
                ans.push_back('0');
            }
            return ans;
        }
        int j=0;
        for(;j<n;j++){
            if(s[j]=='1')
             break;
        }
        for(;j<n;j++){
         if(s[j]=='1')
         ans.push_back('1');
         else
          ans.push_back('0');
        }
         return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.binaryNextNumber(s);
        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends