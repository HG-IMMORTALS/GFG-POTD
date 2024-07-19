//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
//  User function template for C++

class Solution {
  public:
     vector<int> constructLowerArray(vector<int> &nums) {
        int n=nums.size();
        vector<int> stack;
        vector<int> cnt(n,0);
        stack.push_back(nums[n-1]);
        cnt[n-1]=0;
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i]>stack.back())
            {
                stack.push_back(nums[i]);
                cnt[i]=stack.size()-1;
            }
            else
            {
                int ind=lower_bound(stack.begin(),stack.end(),nums[i])-stack.begin();
                stack.insert(stack.begin()+ind,nums[i]);
                cnt[i]=ind;
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int t;

    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int n = arr.size();
        Solution ob;
        vector<int> a = ob.constructLowerArray(arr);
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends