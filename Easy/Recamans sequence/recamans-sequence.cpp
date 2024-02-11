//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution{
public:
 unordered_set<int> s;
  void help(int n,vector<int>&v)
  {
      if(n==0){
        v.push_back(n);
        s.insert(0);
          return;
      }
      help(n-1,v);
      if(v[n-1]-n>0 && s.find(v[n-1]-n)==s.end()){
         v.push_back(v[n-1]-n);
         s.insert(v[n-1]-n);
      }
    
      else{
          s.insert(v[n-1]+n);
          v.push_back(v[n-1]+n);}
 
  }
    vector<int> recamanSequence(int n){
   
        vector<int>v;
        help(n-1,v);
        return v;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<int> ans = ob.recamanSequence(n);
        for(int i = 0;i < n;i++)
            cout<<ans[i]<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends