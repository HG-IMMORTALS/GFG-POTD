//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

    bool kPangram(string str, int k) {
          int arr[26]={0};
        string t="";
        for(int i=0;i<str.length();i++)
        {
            if(str[i]!=' ')t+=str[i];
           
        }
        if(t.length()<26)return 0;
         for(int i=0;i<t.length();i++)
        {
            arr[t[i]-'a']++;
           
        }
        int cnt=0;
        for(int i=0;i<26;i++)
        {
            if(arr[i]==0)cnt++;
        }
        if(cnt<=k)return 1;
        return 0;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        string str;
        getline(cin, str);

        int k;
        cin >> k;

        Solution ob;
        bool a = ob.kPangram(str, k);
        if (a)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends