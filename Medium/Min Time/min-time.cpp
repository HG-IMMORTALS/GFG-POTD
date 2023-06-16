//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
 class Solution {
public:
    #define ll long long
    long long rec(int i , int choose , vector<vector<ll>>&arr , vector<vector<ll>>&dp) {
        if (i == arr.size()) {
            return abs(arr[i - 1][choose]);
        }
        if (dp[i][choose] != -1) {
            return dp[i][choose];
        }
        ll op1 = LLONG_MAX , op2 = LLONG_MAX;
        if (i == 0) {
            op1 = min(op1 , rec(i + 1 , 0 , arr, dp));
        }
        else {
            if (arr[i][1] <= arr[i - 1][choose] and arr[i][2] >= arr[i - 1][choose]) {
                // if choose to go right first then go left
                ll distance = abs(arr[i - 1][choose] - arr[i][2]) + abs(arr[i][2] - arr[i][1]);
                op1 = min(op1 , distance + rec(i + 1, 1 , arr, dp));
                distance = abs(arr[i - 1][choose] - arr[i][1]) + abs(arr[i][2] - arr[i][1]);
                op2 = min(op2 , distance + rec(i + 1 , 2 , arr, dp));
            }
            else {
                // both min and max are at same sides
                if (arr[i][1] <= arr[i - 1][choose] and arr[i][1] <= arr[i][2]) {
                    op1 = min(op1 , abs(arr[i - 1][choose] - arr[i][1]) + rec(i + 1 , 1, arr, dp));
                }
                else {
                    op1 = min(op1 , abs(arr[i - 1][choose] - arr[i][2]) + rec(i + 1 , 2, arr, dp));
                }
            }
        }
        return dp[i][choose] = min(op1, op2);
    }
    long long minTime(int n, vector<int> &locations, vector<int> &types) {
        int mx = *max_element(begin(types) , end(types));

        vector<pair<int, int>> ar(mx + 1 , {INT_MAX , INT_MIN});
        ar[0].first = 0  , ar[0].second = 0;
        
        for (int i = 0; i < n; i++) {
            ar[types[i]].first = min(locations[i], ar[types[i]].first);
            ar[types[i]].second = max(locations[i] , ar[types[i]].second);
        }
        
        vector<vector<ll>> a;
        for (int i = 0; i <= mx; i++) {
            if (ar[i].first == INT_MAX) {
                continue;
            }
            else {
                a.push_back({i , ar[i].first , ar[i].second});
            }
        }
        
        vector<vector<ll>> dp(a.size() + 1, vector<ll>(3, -1));
        return rec(0, 0, a , dp);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        
        
        vector<int> locations(n);
        for(int i=0;i<n;i++){
            cin>>locations[i];
        }
        
        
        vector<int> types(n);
        for(int i=0;i<n;i++){
            cin>>types[i];
        }
        
        Solution obj;
        long long res = obj.minTime(n, locations, types);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends