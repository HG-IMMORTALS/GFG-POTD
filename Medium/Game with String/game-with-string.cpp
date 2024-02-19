//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
   int minValue(string s, int k)
   {
    priority_queue<pair<int,char>> pq;
    map<char,int> mp;
    for(int i=0;i<s.size();i++) mp[s[i]]++;
    for(auto it = mp.begin();it!=mp.end();it++)
    {
        pq.push({it->second,it->first});
    }
    while(k-- && pq.size()>0)
    {
        auto temp = pq.top();
        pq.pop();
        pq.push({(temp.first-1),temp.second});
    }
    int ans = 0;
    while(pq.size()>0)
    {
        ans += (pq.top().first*pq.top().first);
        pq.pop();
    }
    return ans;
   }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends