//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool Search(int N, vector<int>& nums, int target) {
        // Code here
        int n = nums.size();
        int low = 0,high = n-1;

        while(low<=high)
        {
            int mid = low + (high-low)/2;

            if(nums[mid]==target) return true;
            
            if(nums[low]==nums[mid] && nums[high]==nums[mid])
            {
                low++;
                high--;
                continue;
            }

            //left side is sorted
            if(nums[low]<=nums[mid])
            {
                if(nums[low]<= target && target <=nums[mid])
                {
                    high = mid-1;
                }
                else low = mid+1;
            }
            //right side is sorted
            else{
                if(nums[mid]<=target && target<=nums[high])
                {
                    low = mid+1;
                }
                else high = mid-1;
            }
        }
        return  false;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int key;
        cin >> key;

        Solution obj;
        cout << obj.Search(n, a, key) << "\n";
    }
    return 0;
}
// } Driver Code Ends