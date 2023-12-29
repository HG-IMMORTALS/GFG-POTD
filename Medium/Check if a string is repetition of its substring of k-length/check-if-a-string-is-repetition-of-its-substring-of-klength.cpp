//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	
	int kSubstrConcat (int n, string s, int k)
	{
	    if(n%k!=0) return 0;
	    map<string,string>mp;
	    string f=s.substr(0,k);
        string t="";
        
	    for(int i=k;i<n;i++){
	        t+=s[i];
	        if(t.size()==k && t==f){
	            t="";
	        }else if(t.size()==k && f!=t){
	            break;
	        }
	    }

	    for(int i=0;i<n;i+=k){
	        string sys=s.substr(i,k);
	        if(sys==t || sys==f) continue;
	        else return 0;
	    }

	    return 1;
	}
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
	{
		int n; cin >> n;
		string s; cin >> s;
		int k; cin >> k;
        Solution  ob;
		cout << ob.kSubstrConcat (n, s, k) << endl;
	}
}
// } Driver Code Ends