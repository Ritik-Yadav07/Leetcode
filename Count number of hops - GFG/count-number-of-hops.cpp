//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to count the number of ways in which frog can reach the top.
    long long mod=1e9+7;
    long long memo(int n,vector<int>&dp){
        if(n==0) return 1;
        long long fs=0;
        long long ss=0;
        long long ts=0;
        
        if(dp[n]!=-1) return dp[n];
        if(n-1>=0) fs = memo(n-1,dp);
        if(n-2>=0) ss = memo(n-2,dp);
        if(n-3>=0) ts = memo(n-3,dp);
       
        
        return dp[n]=(fs+ss+ts)%mod;
    }
    
    
    
    
    long long countWays(int n)
    {
        
        // your code here
        vector<int>dp(n+1,-1);
        return memo(n,dp)%mod;
        
    }
};



//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends