//{ Driver Code Starts
// C++ program to remove recurring digits from
// a given number
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
    

class Solution{
    //Function to find the leaders in the array.
    public:
    vector<int> leaders(int arr[], int n){
        // Code here
        //O(N^2) solution  -->Brute Force
        //O(N) but O(N) space with stack --> better
        
        //3rd approach O(N) time but O(1) space --> most optimized
        int curr_leader = arr[n-1];
        vector<int>leaders;
        leaders.push_back(curr_leader);
        
        for(int i=(n-2);i>=0 ; i--)
        {
            if(arr[i]>=curr_leader)
            {
                curr_leader = arr[i];
                leaders.push_back(curr_leader);
            }
        }
        
        reverse(leaders.begin(),leaders.end());
        return leaders;
    }
};


//{ Driver Code Starts.

int main()
{
   long long t;
   cin >> t;//testcases
   while (t--)
   {
       long long n;
       cin >> n;//total size of array
        
        int a[n];
        
        //inserting elements in the array
        for(long long i =0;i<n;i++){
            cin >> a[i];
        }
        Solution obj;
        //calling leaders() function
        vector<int> v = obj.leaders(a, n);
        
        //printing elements of the vector
        for(auto it = v.begin();it!=v.end();it++){
            cout << *it << " ";
        }
        
        cout << endl;

   }
}

// } Driver Code Ends