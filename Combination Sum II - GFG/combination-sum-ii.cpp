//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    
    void helper(int i,vector<int>&candidates,int target,int &sum,vector<int>&curr_comb,vector<vector<int>>&res)
    {
        if(sum>target) return;
        if(sum==target){
            res.push_back(curr_comb);
            return;
        }
        
        
        for(int j=i;j<candidates.size();j++)
        {   
            if(j>i && candidates[j]==candidates[j-1]) continue;
            sum+=candidates[j];
            curr_comb.push_back(candidates[j]);
            helper(j+1,candidates,target,sum,curr_comb,res);
            
            sum-=candidates[j];
            curr_comb.pop_back();
        }
        return;
    }
    
    
    
    
    
    
    
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        // Write your code here
        //see neetcode course video
        vector<vector<int>>res;
        vector<int>curr_comb;
        int sum=0;
        sort(candidates.begin(),candidates.end());
        helper(0,candidates,target,sum,curr_comb,res);
        return res;
    }
};

//{ Driver Code Starts.
int main() {

    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> candidates(n);
        for (int i = 0; i < n; ++i) {
            cin >> candidates[i];
        }
        // char marker;
        // cin >> marker;

        Solution obj;

        vector<vector<int>> comb = obj.combinationSum2(candidates, k);
        sort(comb.begin(), comb.end());
        cout << "[ ";
        for (int i = 0; i < comb.size(); i++) {
            cout << "[ ";
            for (int j = 0; j < comb[i].size(); j++) {
                cout << comb[i][j] << " ";
            }
            cout << "]";
        }
        cout << " ]\n";

        // cout << "\n~\n";
    }
    fclose(stdout);
    return 0;
}

// } Driver Code Ends