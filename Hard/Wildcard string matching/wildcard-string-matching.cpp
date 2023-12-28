//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution{
    public:
    bool match(string p, string s)
    {
         int i = 0, j = 0, star = -1, match = 0;
        while (j < s.size()) {
            if (i<p.size() and (p[i] == s[j] || p[i] == '?')) {
                i++;
                j++;
            } else if (p[i] == '*') {
                if (i == p.size() - 1) {
                    return true;
                } else {
                    star = i;
                    match = j;
                    i++;
                }
            } else if (star != -1) {
                i = star + 1;
                match++;
                j = match;
            } else {
                return false;
            }
        }
        while(i<p.size() and p[i]=='*') i++;
        return i == p.size();
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t-->0)
    {
        string wild, pattern;
        cin>>wild>>pattern;
        
        Solution ob;
        bool x=ob.match(wild, pattern);
        if(x)
        cout<<"Yes\n";
        else
        cout<<"No\n";
    }
    return 0;
}
// } Driver Code Ends