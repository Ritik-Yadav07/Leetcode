//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        // your code here
        
        int tail = 0;
        int head = 0;
        vector<int>result;
        deque<int>list;
        
        for(head=0;head<n;head++){
           
           while(list.size()>0 && list.back()<arr[head]){
               list.pop_back();
           }
           
           list.push_back(arr[head]);
           if((head-tail+1)==k){
               result.push_back(list.front());
               if(arr[tail]==list.front())
               {
                   list.pop_front();
               }
               tail++;
           }
        }
        
        return result;
    }
};

//{ Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends