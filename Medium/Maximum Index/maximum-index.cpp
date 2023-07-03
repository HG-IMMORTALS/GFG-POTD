//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    int maxIndexDiff(int arr[], int n) {
    //      int maxDiff = 0;
    //     for(int i = 0; i < n; i++)
    //     {
    //         for(int j = 0; j < n; j++)
    //         {
    //             if(arr[i] <= arr[j])
    //             {
    //                 maxDiff = max(maxDiff, j - i);
    //             }
    //         }
    //     }
    //     return maxDiff;
    // }
                         /*TlE HIT AT 192 TESTCASE*/
    vector<int> min_l(n);
    vector<int> max_r(n);

    int mini = arr[0];
    for (int i = 0; i < n; i++)
    {
        mini = min(mini, arr[i]);
        min_l[i] = mini;
    }

    int maxi = arr[n - 1];
    for (int i = n - 1; i >= 0; i--)
    {
        maxi = max(maxi, arr[i]);
        max_r[i] = maxi;
    }

    int max_len = 0;
    int i = 0, j = 0;

    while (j < n and i < n)
    {
        if (min_l[i] <= max_r[j])
        {
            max_len = max(max_len, (j - i));
            j++;
        }
        else
        {
            i++;
        }
    }
    return max_len;
}
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.maxIndexDiff(a, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends