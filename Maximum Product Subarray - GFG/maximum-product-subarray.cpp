//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(vector<int> nums, int n) {
	    // code here
	    
        long long pf1 = 1;
        long long max1 = INT_MIN;

        long long pf2 = 1;
        long long max2 = INT_MIN;

        for(int i=0;i<n;i++)
        {
            if(pf1==0)
            {
                pf1 = nums[i];
            }
            else{
                pf1 = pf1*nums[i];
            }

            max1 = max(max1,pf1);
        }

        for(int i=n-1;i>=0;i--)
        {
            if(pf2==0)
            {
                pf2 = nums[i];
            }
            else{
                pf2 = pf2*nums[i];
            }

            max2 = max(max2,pf2);
        }

        return max(max1,max2);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends