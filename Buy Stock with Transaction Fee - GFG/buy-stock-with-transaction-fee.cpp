//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
        long long memo(int ind,int buy,vector<long long>&prices,int n,int fee,vector<vector<long long>>&dp)
    {
        if(ind >= n) return 0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];

        if(buy==1)
        {
            return dp[ind][buy] = max(-prices[ind]+memo(ind+1,0,prices,n,fee,dp),0+memo(ind+1,1,prices,n,fee,dp));
        }

        else
        {
            return dp[ind][buy] = max(prices[ind]-fee+memo(ind+1,1,prices,n,fee,dp),0+memo(ind+1,0,prices,n,fee,dp));
        }
    }
    long long maximumProfit(vector<long long>&prices, int n, int fee) {
        
        vector<vector<long long>>dp(n,vector<long long>(2,-1));
        return memo(0,1,prices,n,fee,dp);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        vector<long long> prices;
        
        for(int i=0; i<n; ++i){
            long long x; cin>>x;
            prices.push_back(x);
        }
        
        int fee; cin>>fee;
        
        Solution obj;
        cout<<obj.maximumProfit(prices, n, fee)<<"\n";
    }
    return 0;
}
// } Driver Code Ends