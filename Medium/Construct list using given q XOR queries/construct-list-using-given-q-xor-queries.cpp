//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    vector<int> constructList(int q, vector<vector<int>> &queries) {
          int n=queries.size();
        int last=-1;
        vector<int>ans;
        for(int i=0;i<queries.size();i++){
            if(queries[i][0]==1){
                last=i;
            }
        }
        if(last==-1){
            for(int i=0;i<n;i++){
                ans.push_back(queries[i][1]);
            }
            ans.push_back(0);
        }
        else{
            for(int i=last+1;i<n;i++){
              if(queries[i][0]==0)
                ans.push_back(queries[i][1]);
            }
            int xori=0;
            for(int i=last;i>=0;i--){
                if(queries[i][0]==1)
                 xori=xori^queries[i][1];
                else{
                    queries[i][1]=queries[i][1]^xori;
                }
            }
            for(int i=0;i<=last;i++){
                if(queries[i][0]==0)
                 ans.push_back(queries[i][1]);
            }
            ans.push_back(xori);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int q;
        scanf("%d", &q);

        vector<vector<int>> queries(q, vector<int>(2));
        Matrix::input(queries, q, 2);

        Solution obj;
        vector<int> res = obj.constructList(q, queries);

        Array::print(res);
    }
}

// } Driver Code Ends