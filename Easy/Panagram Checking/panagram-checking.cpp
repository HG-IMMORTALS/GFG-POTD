//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to check if a string is Pangram or not.
    bool checkPangram (string s) {
         int freq[26]={0};
        int cnt=0;
        for(auto ch:s)
        {
            char tmp = tolower(ch);
            if(tmp >= 97 and tmp <= 122 and !freq[tmp-'a'])
            {
                freq[tmp-'a']=1;
                cnt++;
            }
        }
        return cnt==26;
    }

};

//{ Driver Code Starts.

// Driver Program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--){
        string s;
        getline(cin, s);
        Solution obj;
        if (obj.checkPangram(s) == true)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
    return(0);
}

// } Driver Code Ends