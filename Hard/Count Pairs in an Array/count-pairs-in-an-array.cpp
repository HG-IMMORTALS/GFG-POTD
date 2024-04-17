//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    int countPairs(int arr[] , int n ) 
    {
        vector<pair<int, int>> values; 
        for (int i = 0; i < n; ++i) {
            values.emplace_back(i * arr[i], i);
        }
        sort(values.begin(), values.end(), [&](const pair<int,int>& a, const pair<int,int>& b) {
            if (a.first == b.first) return a.second < b.second;
            return a.first < b.first;
        });
        vector<int> fenwick(n+1, 0);
         auto update = [&](int idx, int delta) {
            for (++idx; idx <= n; idx += idx & -idx)
                fenwick[idx] += delta;
        };
         auto query = [&](int idx) {
            int sum = 0;
            for (++idx; idx > 0; idx -= idx & -idx)
                sum += fenwick[idx];
            return sum;
        };
        int count = 0;
        for (int i = n-1; i >= 0; --i) {
            int idx = values[i].second;
            count += query(idx - 1); 
            update(idx, 1); 
        }
        return count;
    }
};

//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	Solution ob;
    	cout<<ob.countPairs(a, n)<<endl;
    }
}
// } Driver Code Ends