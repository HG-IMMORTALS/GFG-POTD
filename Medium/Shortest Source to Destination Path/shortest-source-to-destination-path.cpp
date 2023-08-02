//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
vector<pair<int,int>>moves={
    {0,1},{0,-1},{1,0},{-1,0}
};
class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        int r=A.size();
        int c=A[0].size();
        if(A[0][0]==0) return -1;
        queue<pair<int,int>>q;
        q.push({0,0});
        
        int level=-1;
        bool found=false;
        while(q.size()>0 && !found)
        {
            int n=q.size();
            for(int i=0;i<n;++i)
            {
                pair<int,int>node=q.front();
                q.pop();
                
                if(node.first==X && node.second==Y)
                {
                    found=true;
                    break;
                }
                
                for(auto move:moves)
                {
                    int x=node.first+move.first;
                    int y=node.second+move.second;
                    if(x>=0 && x<r && y>=0 && y<c && A[x][y])
                    {
                        q.push({x,y});
                        A[x][y]=0;
                    }
                }
            }
            level+=1;
        }
        return (found)?level:-1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends