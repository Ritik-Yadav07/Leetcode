//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:  

    int findMin(int arr[], int n){
        //complete the function here
        int low=0;
        int high=n-1;
        
        int res = INT_MAX;
        
        while(low<=high)
        {
            int mid = low+(high-low)/2;
           
           //left is sorted
            if(arr[low]<=arr[mid])
            {
                res = min(res,arr[low]);
                low = mid+1;
            }
            // right is sorted
            else{
                res = min(res,arr[mid]);
                high = mid-1;
            }
        }
        return res;
        
    }
};

//{ Driver Code Starts.


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution ob;
		cout<<ob.findMin(a, n)<<endl;
	}
	return 0;
}
// } Driver Code Ends