//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
 
class Solution
{
    public:
    // Function for finding maximum AND value.
    
    bool checkBit(int num,int i)
    {
        if((num & (1<<i))==0) return false;
        return true;
    }
    int maxAND (int arr[], int N)
    {
        // Your code here
        
        int ans = 0;
        for(int i=31;i>=0;i--)
        {
            int c = 0;
            for(int j = 0;j<N;j++)
            {
                if(checkBit(arr[j],i)==true)
                {
                    c++;
                }
            }
            
            if(c>=2)
            {
                ans = ans + (1<<i);
                for(int j = 0;j<N;j++)
                {
                    if(checkBit(arr[j],i)==false){
                        arr[j] = 0;
                    }
                }
            }
        }
        return ans;
        
        
    }
};

//{ Driver Code Starts.
 
// Driver function
int main()
{
    int t;
    cin>>t;//testcases
    while(t--)
    {
        int n;
        cin>>n;//input n
        int arr[n+5],i;
        
        //inserting elements
        for(i=0;i<n;i++)
        cin>>arr[i];
        Solution obj;
        //calling maxAND() function
        cout <<  obj.maxAND(arr,n)<<endl;
    }
    return 0;
}
// } Driver Code Ends