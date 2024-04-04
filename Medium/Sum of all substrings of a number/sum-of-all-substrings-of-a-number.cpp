//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    int mod=int(1e9)+7;
    public:
    //Function to find sum of all possible substrings of the given string.
    long long sumSubstrings(string s){
        long long n=s.size();
        long long rep=0;
        long long prev=0, sum=0;
        for(int i=n-1;i>=0;i--){
            long long num=s[i]-'0';
            // long long rep=(pow(10, n-i)-1)/9;
            rep=((10*rep)%mod+1)%mod;
            prev=(prev+(rep*num)%mod)%mod;
            sum= (sum+prev)%mod;
        }
        return sum;
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking string
        string s;
        cin>>s;
        Solution ob;
        //calling sumSubstrings() function
        cout << ob.sumSubstrings(s) << endl;
        
    }
    return 0;
}

// } Driver Code Ends