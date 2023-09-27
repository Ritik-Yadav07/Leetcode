//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// Function for finding maximum and value pair
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
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        Solution ob;
        cout <<  ob.maxAND(arr,n)<<endl;
    }
    return 0;
}
// } Driver Code Ends