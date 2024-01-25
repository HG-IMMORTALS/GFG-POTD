//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{   
public:
    bool prime[10001];
    void sieve(){
        memset(prime, 1, sizeof prime);
        prime[0] = prime[1] = 0;
        for(int i=2; i*i<=10000; i++){
            if(prime[i]){
                for(int j=i*i; j<=10000; j+=i){
                    prime[j] = 0;
                }
            }
        }
    }
    int solve(int num1,int num2)
    {   
        sieve();
        queue<pair<int,int>> q;
        q.push({num1, 0});
        int vis[10001] = {0};
        vis[num1] = 1;
        while(!q.empty()){
            int num = q.front().first;
            int cost = q.front().second;
            q.pop();
            if(num == num2) return cost;
            for(int i=0; i<4; i++){
                for(int j = (i == 0 ? 1 : 0); j<=9; j++){
                    string no = to_string(num);
                    char c = '0' + j;
                    if(no[i] != c){
                        no[i] = c;
                        int noo = stoi(no);
                        if(prime[noo] && !vis[noo]){
                            q.push({noo, cost + 1});
                            vis[noo] = 1;
                        }
                    }
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.
signed main()
{
  int t;
  cin>>t;
  while(t--)
  {
      int num1,num2;
      cin>>num1>>num2;
      Solution obj;
      int answer=obj.solve(num1,num2);
      cout<<answer<<endl;
  }
}
// } Driver Code Ends