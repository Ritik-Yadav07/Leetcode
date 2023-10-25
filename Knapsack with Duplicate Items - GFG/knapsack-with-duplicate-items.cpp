//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    int memo(int index,int W,int val[],int wt[],vector<vector<int>>&dp){
        //Base Cases
        if(index==0){
            //not these base case of 0/1 knapsack
            // if(wt[0]<=W) return val[0];
            // else return 0;
            
            //here is unbounded knapsack i.e. infinite supply
            return ((W/wt[0])*val[0]);
        }
        
        if(dp[index][W]!=-1) return dp[index][W];
        int nottake = 0+memo(index-1,W,val,wt,dp);
        int take = INT_MIN;
        if(wt[index]<=W){
            take = val[index] + memo(index,W-wt[index],val,wt,dp);
        }
        return dp[index][W] = max(nottake,take);
    }


    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        vector<vector<int>>dp(N,vector<int>(W+1,-1));
        return memo(N-1,W,val,wt,dp);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends