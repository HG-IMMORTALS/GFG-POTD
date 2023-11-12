//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to check if a string can be obtained by rotating
    //another string by exactly 2 places.
    bool isRotated(string str1, string str2)
    {
        if(str1.length()!=str2.length()) return false;
        if(str1.size()==1 || str1.size()==2) return str1==str2;
        int n=str1.length();
        str1=str1+str1;
        int found=str1.find(str2);
        if(found==2||found==n-2) 
            return true;
        return false;
    }

};


//{ Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string b;
		cin>>s>>b;
		Solution obj;
		cout<<obj.isRotated(s,b)<<endl;
	}
	return 0;
}

// } Driver Code Ends