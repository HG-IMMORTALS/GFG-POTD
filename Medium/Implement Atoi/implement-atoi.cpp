//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        //Your code here
             int ans=0;
        for(int i=0;i<str.length();++i){
            if(str[0]=='-' && i==0){
                continue;
            }
            else if(str[i]<47 || str[i]>57){
                return -1;
            }
            else{
                ans=ans*10+((int)str[i]-(int)'0');
            }
        }
        if(str[0]=='-'){
            ans=-ans;
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends