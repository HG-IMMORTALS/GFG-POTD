//{ Driver Code Starts
 
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int isPalindrome(string S)
	{
	 int shuru=0;
     int khatam=S.length()-1;
     while(shuru<khatam)
     {
         if (S[shuru]!=S[khatam]) return 0;
         else
         {
             shuru++;
             khatam--;
         }
	 }
	 return 1;
	}
};

//{ Driver Code Starts.

int main() 
{
   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.isPalindrome(s) << "\n";
   	}

    return 0;
}
// } Driver Code Ends