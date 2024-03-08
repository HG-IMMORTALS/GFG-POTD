//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	bool sameFreq(string s)
	{
	     vector<int> v(26, 0);
        
        for(int i=0;i<s.size();i++){
           v[s[i]-'a']++;
        }
        int f1=0, f2=0, cnt1=0, cnt2=0;
        
        for(auto f: v){
            if(f==0) continue;
            
            if(f1==0){
                f1 = f;
                cnt1 = 1;
            }
            else if(f==f1) cnt1++;
            else if(f2==0){
                f2 = f;
                cnt2 = 1;
            }
            else if(f2==f) cnt2++;
            else return false;
            
        }
        if(f2==0) return true;
        if(cnt1<=1 or cnt2<=1){
            return abs(f2-f1) <= 1;
        }
        return false;
	}
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.sameFreq(s)<<endl;
    }
}



// } Driver Code Ends