//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int kthElement(int k, vector<int>& arr1, vector<int>& arr2) {
        int l1=0,l2=0,n1=arr1.size(),n2=arr2.size(),ans=-1;
        while(k>0){
            if(l1<n1 && l2<n2){
                if(arr1[l1]<arr2[l2]) ans=arr1[l1++];
                else ans=arr2[l2++];
            }
            else if(l1<n1) ans=arr1[l1++];
            else ans=arr2[l2++];
            k--;
        }
        return ans;
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m, k;
        cin >> k;
        cin.ignore();
        string input;
        int num;
        vector<int> arr1, arr2;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr1.push_back(num);
        }

        getline(cin, input);
        stringstream s3(input);
        while (s3 >> num) {
            arr2.push_back(num);
        }

        Solution ob;
        cout << ob.kthElement(k, arr1, arr2) << endl;
    }
    return 0;
}
// } Driver Code Ends