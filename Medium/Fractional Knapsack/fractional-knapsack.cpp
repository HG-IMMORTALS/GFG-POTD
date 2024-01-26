//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
      static bool comp(Item a, Item b)
    {
        return ((1.0 * a.value)/(a.weight*1.0))>((1.0*b.value)/(b.weight*1.0));
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr,arr+n,comp);
        double ans=0;
        for (int i=0;i<n;i++)
        {
            if (W>=arr[i].weight) 
            {
                ans+=arr[i].value;
                W-=arr[i].weight;
            }
            else
            {
                ans+=arr[i].value*((1.0*W)/(1.0*arr[i].weight));
                break;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(6)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends