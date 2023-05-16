//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool isGreaterOrEqual(int num,int target)
    {
        return num>=target;
    }
    int searchInsertK(vector<int>Arr, int N, int k)
    {
        // code here
        int lo = -1;
        int hi = N;
        while(lo+1<hi)
        {
            int mid = lo+(hi-lo)/2;
            if(isGreaterOrEqual(Arr[mid],k))
            {
                hi = mid;
            }
            else{
                lo = mid;
            }
        }
        return hi;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        vector<int>Arr(N);
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int k;
        cin>>k;
        Solution obj;
        cout<<obj.searchInsertK(Arr, N, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends