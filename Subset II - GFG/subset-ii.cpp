//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {

  public:
    void helper(int i,vector<int>&nums,vector<int>&temp,vector<vector<int>>&res)
    {   
        int n = nums.size();
        if(i>=n){
            // sort(temp.begin(),temp.end());
            res.push_back(temp);
            return;
        }
        
        //decision to include nums[i]
        temp.push_back(nums[i]);
        helper(i+1,nums,temp,res);
        temp.pop_back();
        
        //decision NOT to include nums[i]
        while(i+1<n && nums[i]==nums[i+1])
        {
            i++;
        }
        helper(i+1,nums,temp,res);
        
    }
    vector<vector<int>> printUniqueSubsets(vector<int>& nums) {
        // Write your code here
        sort(nums.begin(),nums.end());
        vector<vector<int>>res;
        vector<int>temp;
        helper(0,nums,temp,res);
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        // char marker;
        // cin >> marker;

        Solution obj;
        vector<vector<int>> ans = obj.printUniqueSubsets(nums);
        sort(ans.begin(), ans.end());
        //   printAns(ans);
        cout << "[ ";
        for (int i = 0; i < ans.size(); i++) {
            cout << "[ ";
            for (int j = 0; j < ans[i].size(); j++) cout << ans[i][j] << " ";
            cout << "]";
        }
        cout << " ]\n";

        // cout<< "~\n";
    }

    return 0;
}

// } Driver Code Ends