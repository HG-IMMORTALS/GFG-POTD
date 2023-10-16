//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    int kx[4] = {0 , 0 , 1, -1};
    int ky[4] = {1 , -1 , 0, 0};
public:
     int count(int i,int j,int n,int m,vector<vector<int>>&grid,vector<vector<bool>>&vis,vector<vector<int>>&mapper,int islandNo){
        int c = 0;
        if(i >=0 && j >=0 && i < n && j < m){
            if(!vis[i][j]){
                c++;
                mapper[i][j] = islandNo;
                vis[i][j] = 1;
                for(int p = 0 ; p < 4;p++){
                    int px = i + kx[p], py = j + ky[p];
                    if(px >= 0 && py >= 0 && px < n && py < m && !vis[px][py] && grid[px][py]){
                        c += count(px,py,n,m,grid,vis,mapper,islandNo);
                    }
                }
            }
        }
        return c;
    }
    int largestIsland(vector<vector<int>>& grid) 
    {
        int n = grid.size(), m = grid[0].size();
        vector<int> sizeOfIsland;
        vector<vector<bool>> vis (n,vector<bool> (m,0));
        vector<vector<int>> mapper(n,vector<int> (m,-1));
        int islandNo = 0;
        for(int i = 0 ; i < n;i++){
            for(int j = 0 ; j < m;j++){
                if(grid[i][j] && !vis[i][j]){
                    sizeOfIsland.push_back(count(i,j,n,m,grid,vis,mapper,islandNo));
                    islandNo++;
                }
            }
        }
        int res = 0;
        for(int &i: sizeOfIsland) res = max(res,i);
        for(int i = 0 ; i < n;i++){
            for(int j = 0 ; j < m;j++){
                if(!grid[i][j]){
                    set<int> s;
                    for(int p = 0 ; p < 4;p++){
                        int px = i + kx[p], py = j + ky[p];
                        if(px >= 0 && py >= 0 && px < n && py < m){
                            if(mapper[px][py] != -1)
                                s.insert(mapper[px][py]);
                        }
                    }
                    int newisland = 1;
                    for(auto &r: s){
                        newisland += sizeOfIsland[r];
                    }
                    res = max(res, newisland);
                }
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin >> t;
    while(t--){

        int n;
        cin>>n;
        vector<vector<int>>grid(n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>grid[i][j];
        Solution ob;
        cout<<ob.largestIsland(grid)<<endl;
    }
    return 0;
}

// } Driver Code Ends