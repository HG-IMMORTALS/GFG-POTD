//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    vector<vector<int>> kTop(vector<int>& arr, int n, int k) {
        vector<int> place(k+1 , 0);
        vector<vector<int>> ans;
        unordered_map<int,int> mp;
        for(int i = 0 ; i < n ; i++)
        {
            place[k] = arr[i];
            mp[arr[i]]++;
            
            int ele =find( place.begin() , place.end()-1,arr[i])-place.begin()-1;
            
            for(int j = ele ; j>=0 ;j--)
            {
                if(mp[place[j]] < mp[place[j+1]] || (mp[place[j]] == mp[place[j+1]] && place[j]>place[j+1]))
                    swap(place[j], place[j+1]);
                else   break;
            }
            vector<int> temp;
            for(int j= 0 ; j<k && place[j]!=0; j++)
                temp.push_back(place[j]);
            ans.push_back(temp);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        
        vector<int> a(N);
        Array::input(a,N);
        
        Solution obj;
        vector<vector<int>> res = obj.kTop(a, N, K);
        
        for(auto it:res)
            Array::print(it);
        
    }
}

// } Driver Code Ends