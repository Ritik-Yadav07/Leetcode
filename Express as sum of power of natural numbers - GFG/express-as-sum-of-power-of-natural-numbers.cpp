//{ Driver Code Starts
// Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
   const int mod = 1e9+7;
    
    int memo(int index,int n,int &x,vector<vector<int>>&dp)
    {
        if(n==0) return 1;
        if(index>n) return 0;
        if(dp[index][n]!=-1) return dp[index][n];
        
        int notPick = memo(index+1,n,x,dp);
        int pick = 0;
        if(n-pow(index,x)>=0)
        {
            pick = memo(index+1,n-pow(index,x),x,dp);
        }
        return dp[index][n] = (pick+notPick)%mod;
    }
    int numOfWays(int n, int x)
    {
        // code here
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return memo(1,n,x,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int  n, x;
        cin >> n >> x;
        Solution ob;
        cout<<ob.numOfWays(n, x)<<endl;
    }
    return 0;
}

// } Driver Code Ends