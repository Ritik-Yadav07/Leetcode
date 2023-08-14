//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    vector<int> increment(vector<int> digits ,int N) {
        // code here
        vector<int>output;
        int carry = 1;

        
        
        for(int i=N-1;i>=0;i--){
            
            int sum = digits[i]+carry;
            if(sum<=9){
                carry = 0;
                output.push_back(sum);
            }else{
                carry = 1;
                output.push_back(0);
            }
        }
        
        if(carry) output.push_back(carry);
        reverse(output.begin(),output.end());
        return output;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        char c;
        
        cin>>N;
        vector<int> arr(N);
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        vector<int> res = ob.increment(arr,N);
        for(int i: res)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends