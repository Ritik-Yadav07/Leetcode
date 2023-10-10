//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    int omaxi_sum = 0; //overall maximum sum of increasing sequence
	    vector<int>dp(n,0);
	    for(int i=0;i<n;i++)
	    {
	        int maxi_sum = 0;
	        for(int j=0;j<i;j++)
	        {
	            if(arr[j]<arr[i])
	            {
	                if(dp[j]>maxi_sum)
	                {
	                    maxi_sum = dp[j];
	                }
	            }
	            
	        }
	        dp[i] = maxi_sum + arr[i];
	        omaxi_sum = max(omaxi_sum,dp[i]);
	    }
	    
	    return omaxi_sum;
	    
	}  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends