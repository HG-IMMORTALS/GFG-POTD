//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int Count(vector<vector<int> >& matrix) {
        int rL=matrix.size();
        int cL=matrix[0].size();
        int ans=0;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(matrix[i][j]==0)
                continue;
                int count = 0;
                int r[]={-1,-1,-1,0,1,1,1,0};
                int c[]={-1,0,1,1,1,0,-1,-1};
                for(int k=0;k<8;k++)
                {
                    int nr=i+r[k];
                    int nc=j+c[k];
                    if(nr>=0 && nr<rL && nc>=0 && nc<cL && matrix[nr][nc]==0)
                    count++;
                }
                if(count!=0 && count%2==0)
                ans++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.Count(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends