//{ Driver Code Starts
//Initial template for c++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int DifferOne(long int a, long int b) { 
        //complete the function here
        long int xorr = a^b;
        int count = __builtin_popcount(xorr);
        return count==1;
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        long int a, b;
        cin >> a >> b;
        Solution ob;
        cout << ob.DifferOne(a, b) << endl;
    
    }
    return 0; 
} 

// } Driver Code Ends