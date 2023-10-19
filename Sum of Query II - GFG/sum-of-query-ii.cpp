//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> querySum(int n, int arr[], int q, int queries[])
    {
        // code here
        vector<int>prefixSum(n+1);
        prefixSum[0]=0;
        for(int i=1;i<=n;i++)
        {
            prefixSum[i] = arr[i-1] + prefixSum[i-1];
        }
        
        vector<int>res;
        for(int i=0;i<2*q;i+=2)
        {
            int l = queries[i];
            int r = queries[i+1];
            
            int ans = prefixSum[r]-prefixSum[l-1];
            res.push_back(ans);
            
        }
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, q;
        cin>>n;
        int arr[n];
        for(int i = 0;i < n;i++)
            cin>>arr[i];
        cin>>q;
        int queries[2*q];
        for(int i = 0;i < 2*q;i += 2)
            cin>>queries[i]>>queries[i+1];
        
        Solution ob;
        vector<int> ans = ob.querySum(n, arr, q, queries);
        for(int u: ans)
            cout<<u<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends