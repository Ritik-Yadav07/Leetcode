//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isValid(int nums[],int N,int K,int maxi)
    {
        int subArrayCount = 1; //there is student count
        int sum = 0;

        for(int i=0;i<N;i++)
        {
            sum+=nums[i];
            if(sum>maxi)
            {
                subArrayCount++;
                sum = nums[i];
            }
        }

        if(subArrayCount>K) return false;
        return true;
    }
    int splitArray(int nums[] ,int N, int K) {
        // code here
        //exact same problem variation of Book allocation problem
        //aditya verma
        
        if(N<K) return -1;

        int start = INT_MIN;  // this will maxi in array
        int end = 0;  // this will sum of array element
        int res = -1;

        for(int i=0;i<N;i++)
        {
            end+=nums[i];
            start = max(start,nums[i]);
        }

        while(start<=end)
        {
            int mid = start + (end-start)/2;

            if(isValid(nums,N,K,mid)){
                res = mid;
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }

        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends