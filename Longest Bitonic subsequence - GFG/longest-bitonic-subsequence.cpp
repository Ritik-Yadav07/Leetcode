//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int LongestBitonicSequence(vector<int>nums)
	{
	    // code here
	    int n = nums.size();
	    vector<int>lis(n,0);
	    
	    for(int i=0;i<n;i++)
	    {
	        int maxi = 0;
	        for(int j=0;j<i;j++)
	        {
	            if(nums[j]<nums[i])
	            {
	                if(lis[j]>maxi)
	                {
	                    maxi = lis[j];
	                }
	            }
	        }
	        
	        lis[i] = maxi+1;
	    }
	    
	    
	    vector<int>lds(n,0); //longest decreasing subsequence
	    for(int i=n-1;i>=0;i--)
	    {
	        int maxi = 0;
	        for(int j=n-1;j>i;j--)
	        {
	            if(nums[j]<nums[i])
	            {
	                if(lds[j]>maxi)
	                {
	                    maxi = lds[j];
	                }
	            }
	        }
	        
	        lds[i] = maxi + 1;
	    }
	    
	    int omax = 0;
	    for(int i=0;i<n;i++)
	    {
	        omax = max(omax,lis[i]+lds[i]-1);
	    }
	    return omax;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.LongestBitonicSequence(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends