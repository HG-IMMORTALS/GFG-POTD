//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	string removeDuplicates(string str) {
	     int freq[52] = {0}, n = str.size();
	    string res;
	    
	    for(int i=0; i<n; i++){
	        int ind = -1;
	        
            if(str[i]>=97) ind = str[i]-97;
            else ind = str[i]-65+26;
            
            if(!freq[ind]) res.push_back(str[i]);
            freq[ind]++;
	    }
	    return res;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        auto ans = ob.removeDuplicates(str);

        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends