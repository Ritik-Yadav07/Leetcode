//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  void backTrack(vector<int>&arr,vector<int>&tempList,vector<bool>&used,vector<vector<int>>&res){
      
      if(tempList.size()==arr.size()){
          res.push_back(tempList);
      }
      for(int i=0;i<arr.size();i++){
          
          if(used[i]==true) continue;
          else if(i>0 && arr[i]==arr[i-1] && !used[i-1]) continue;
          else{
              used[i]=true;
              tempList.push_back(arr[i]);
              backTrack(arr,tempList,used,res);
              used[i]=false;
              tempList.pop_back();
          }
      }
      return;
  }
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        // code here
        sort(arr.begin(),arr.end());
        vector<vector<int>>res;
        vector<int>tempList;
        vector<bool>used(n,false);
        backTrack(arr,tempList,used,res);
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;
        vector<int> arr(n);
        
        for(int i=0 ; i<n ; i++)
            cin>>arr[i];

        Solution ob;
        vector<vector<int>> res = ob.uniquePerms(arr,n);
        for(int i=0; i<res.size(); i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<res[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends