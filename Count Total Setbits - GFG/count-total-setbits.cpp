//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    int largestPowerofTwo(int n)
{
    int x = 0;
    while((1<<x)<=n)
    {
        x++;
    }
    return x-1;
}
    
    int countBits(int N){
        // code here
    //   See pepcoding channel for bits
       if(N==0) return 0;
       
       int x = largestPowerofTwo(N);
       int btill2x = x * (1<<(x-1));
       int msb2xton = N - (1<<x) + 1;
       int rest = N-(1<<x);
       
       return btill2x + msb2xton + countBits(rest);
      
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.countBits(N)<<"\n";
    }
    return 0;
}
// } Driver Code Ends