//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int singleElement(int arr[] ,int N) {
          sort(arr,arr + N);
         if(N==1) return arr[0];
         if(arr[0]!=arr[1]) return arr[0];
         if(arr[N-1]!=arr[N-2]) return arr[N-1];
         
         for(int i=1;i<N-1;i++){
             if(arr[i-1]!=arr[i] && arr[i]!=arr[i+1]) return arr[i];
         }
         return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.singleElement(arr,N);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends