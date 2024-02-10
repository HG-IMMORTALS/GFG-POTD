//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;

class GFG
{
    public static void main(String args[])throws IOException
    {
        
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while(t-- > 0)
        {
            
            int  k = Integer.parseInt(read.readLine());
            int  n = Integer.parseInt(read.readLine());
            int arr[][] = new int[n][n];
            String input_line1[] = read.readLine().trim().split("\\s+");
            int c = 0;
            for(int i=0;i<n;i++){
                for(int j = 0;j<n;j++){
                    arr[i][j] = Integer.parseInt(input_line1[c]);
                    c++;
                }
            }
            Solution obj = new Solution();
            System.out.println(obj.numberOfPath(n, k, arr));
        }
    }
}

// } Driver Code Ends


//User function Template for Java
class Solution {
    static long count=0;
    Solution(){
        this.count = 0;
    }
    long numberOfPath(int n, int k, int [][]arr) {
        
        int sum = 0;
        countPath(arr,n,k,sum,0,0);
        return count;
       
    }
    public static void countPath(int arr[][],int n,int k,int sum,int i,int j){
        
        if(i<0 || j<0 || i>=n || j>=n || sum>k){
            return;
        }
        sum += arr[i][j];
        if(sum>=k && (i!=n-1 && j!=n-1)){
            return;
        }
        if(sum==k && (i==n-1 && j==n-1)){
            count++;
            return;
        }
        countPath(arr,n,k,sum,i+1,j);//down
        countPath(arr,n,k,sum,i,j+1);//left
    }
}