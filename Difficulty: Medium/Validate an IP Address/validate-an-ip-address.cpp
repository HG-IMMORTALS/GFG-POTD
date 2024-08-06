//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int isValid(string str) {
        // code here
        int dot = 0;
        string temp = "";
        for(int i = 0 ; i < str.length() ; i++){
            if(str[i] == '.'){
                dot++;
                if(temp.empty()) return false;
                else if(temp.size() > 1 && temp[0] == '0') return false;
                int num = stoi(temp);
                if(num < 0 || num > 256) return false;
                temp = "";
            }
            else temp += str[i];
        }
        if(temp.empty()) return false;
        else if(temp.size() > 1 && temp[0] == '0') return false;
        int num = stoi(temp);
        if(num < 0 || num > 256) return false;
        return dot == 3 ? true : false;
    }
};

//{ Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        // if (s.size() == 3) {
        //     cout << "false" << endl;
        //     return 0;
        // }
        Solution ob;
        bool f = ob.isValid(s);
        if (f)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends