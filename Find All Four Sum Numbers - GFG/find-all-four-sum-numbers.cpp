//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int target) {
        // Your code goes here
        int n = arr.size();
        vector<vector<int>>ans;
        if(n<4) return ans;
        
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++){
            
            for(int j=(i+1);j<n;j++){
                
                int X = target-(arr[i]+arr[j]);
                int left = j+1;
                int right=n-1;
                while(left < right){
                    int leftElement=arr[left];
                    int rightElement=arr[right];
                    if(leftElement+rightElement > X) right--;
                    else if(leftElement+rightElement < X) left++;
                    else{
                        ans.push_back({arr[i],arr[j],arr[left],arr[right]});
                        //skiping duplicates
                        while(left<right && arr[left]==leftElement) left++;
                        while(left<right && arr[right]==rightElement) right--;
                        
                    }
                }
                //skiping duplicates
                while(j+1<n && arr[j]==arr[j+1]) j++;
                
            }
            //skiping duplicates
                while(i+1<n && arr[i]==arr[i+1]) i++;
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends