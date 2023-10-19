//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the minimum element in sorted and rotated array.
    int minNumber(int arr[], int low, int high)
    {
        // Your code here
        int ans  = arr[0];
        int mid;
        while(low<=high)
        {
         mid = low + (high-low)/2;
         
         //Left side sorted array ,so will go in right for minimum
         if(arr[mid]>=arr[0]) 
         {
            low = mid+1; 
         }
         else{
             //right side sorted array,so go in left 
             ans = arr[mid];
             high = mid-1;
         }
        }
        return ans;
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
		int a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];	
		Solution obj;
		cout << obj.minNumber(a,0,n-1) << endl;
	}
	return 0;
}
// } Driver Code Ends