//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

#define ll long long
class Solution {
  public:
  
   ll dfs(int i,int j,vector<vector<int>>& matrix,vector<vector<ll>>& dp){
        if(dp[i][j] != -1)
            return dp[i][j];
            
        int dr[] = {0,1,0,-1};
        int dc[] = {1,0,-1,0};
        
        ll temp = 1;
        for(int k = 0; k < 4; k++){
            
            int nr = i + dr[k];
            int nc = j + dc[k];

            if(nr >= 0 and nr < matrix.size() and nc >= 0 and nc < matrix[0].size() and matrix[nr][nc] > matrix[i][j]){
                    ll x = 1+dfs(nr,nc,matrix,dp);
                    temp = max(temp,(ll)x);
            }
        }

        return dp[i][j] = temp;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix, int n, int m) {

        // Code here
        vector<vector<ll>> dp(n,vector<ll>(m,-1));
        ll maxi = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                maxi = max(maxi,dfs(i,j,matrix,dp));
            }
        }
        
        return maxi;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> matrix[i][j];
            }
        }
        Solution obj;
        cout << obj.longestIncreasingPath(matrix, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends