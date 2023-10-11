//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int memo(int ind,int buy,int cap,int prices[],int n,vector<vector<vector<int>>>&dp)
    {
        if(ind == n || cap==0) return 0;
        if(dp[ind][buy][cap]!=-1) return dp[ind][buy][cap];

        if(buy==1)
        {
            return dp[ind][buy][cap] = max(-prices[ind]+memo(ind+1,0,cap,prices,n,dp),0+memo(ind+1,1,cap,prices,n,dp));
        }
        else{
            return dp[ind][buy][cap] = max(prices[ind]+memo(ind+1,1,cap-1,prices,n,dp),0+memo(ind+1,0,cap,prices,n,dp));
        }
    }
    int maxProfit(int k, int n, int prices[]) {
        // code here
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return memo(0,1,k,prices,n,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}
// } Driver Code Ends