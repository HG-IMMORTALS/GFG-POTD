//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

  public:
    int findSwapValues(int a[], int n, int b[], int m) {
        // Your code goes here
         int firstarraysum = 0;
        int secondarraysum = 0;
        
        for(int i=0; i<n; i++){
            firstarraysum += a[i];
        }
        for(int j=0; j<m; j++){
            secondarraysum += b[j];
        }
        
        if(firstarraysum == secondarraysum){
            return 1;
        }
        int botharrayssum = firstarraysum + secondarraysum;
        if(botharrayssum%2){
            return -1;
        }
        int equalsum = (botharrayssum) / 2;
        
        int difference = (secondarraysum-equalsum);
        
        sort(a, a+n);
        sort(b, b+m);
        
        int i=0, j=0;
        
        while(i < n && j < m){
           if(b[j]-a[i] > difference){
               i++;
           }
           else if(b[j] - a[i] < difference){
               j++;
           }
           else{
               return 1;
           }
        }
        
        return -1;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n];
        int b[m];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];

        Solution ob;
        cout << ob.findSwapValues(a, n, b, m);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends