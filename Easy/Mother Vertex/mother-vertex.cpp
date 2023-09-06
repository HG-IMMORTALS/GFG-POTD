//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution 
{
    public:
    //Function to find a Mother Vertex in the Graph.
    int c=0;
    void dfs(int v,vector<int> &visited,vector<int>adj[])
    {
        visited[v]=1;
        c++;
        for(int i=0;i<adj[v].size();i++) 
        {
            if(!visited[adj[v][i]]) dfs(adj[v][i],visited,adj);
        }
    }
	int findMotherVertex(int v, vector<int>adj[])
	{
	    vector<int>visited(v,0);
	    int i;
	    for(i=0;i<v;i++)
	    {
	        if(!visited[i]) dfs(i,visited,adj);
	        if(c==v) break;
	    }
	    c=0;
	    for(int i=0;i<v;i++) visited[i]=0;
	    dfs(i,visited,adj);
	    if(c==v) return i;
	    return -1;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends