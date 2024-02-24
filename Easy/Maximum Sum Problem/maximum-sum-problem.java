//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;
class GfG
{
    public static void main(String args[])
        {
            Scanner sc = new Scanner(System.in);
            int t = sc.nextInt();
            while(t-->0)
                {
                    int n = sc.nextInt();
                    Solution ob = new Solution();
                    System.out.println(ob.maxSum(n));
                }
        }
}    
// } Driver Code Ends


//User function Template for Java

class Solution
{
        public int maxSum(int n)
        {
            return maxS(n);
        }
        public int maxS(int n)
        {
            if(n<=11) return n;
        int sum1=0;
        int sum2=0;
        sum1=n/2+n/3+n/4;
        sum2=maxS(n/2)+maxS(n/3)+maxS(n/4);
        int t=Math.max(sum1,sum2);
        return t;
        }
}
